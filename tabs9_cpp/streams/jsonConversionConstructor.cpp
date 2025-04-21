#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <stdexcept>

/*-----------------------------------------------------------
|  Custom exception type
*----------------------------------------------------------*/
class json_exception : public std::exception {
    std::string m_msg;
public:
    explicit json_exception(std::string  m) : m_msg(std::move(m)) {}
    const char* what() const noexcept override { return m_msg.c_str(); }
};

/*-----------------------------------------------------------
|  Minimal JSON class – teacher‑style
*----------------------------------------------------------*/
class json {
public:
    /* ---------- supported kinds ---------- */
    enum class type_t { null, number, boolean, string, dictionary };

private:
    /* ---------- data members ---------- */
    type_t  m_type   = type_t::null;
    double  m_num    = 0.0;
    bool    m_bool   = false;
    std::string                                  m_str;
    std::vector<std::pair<std::string, json>>    m_dict;

public:
    /* ---------- conversion constructors ---------- */
    json()                           = default;               // null
    json(double d)    : m_type(type_t::number) , m_num(d) {}
    json(bool   b)    : m_type(type_t::boolean), m_bool(b) {}
    json(char const* s): m_type(type_t::string) , m_str(s)  {}
    json(std::string  s): m_type(type_t::string) , m_str(std::move(s)) {}

    /* ---------- type queries ---------- */
    bool is_null()       const { return m_type == type_t::null; }
    bool is_number()     const { return m_type == type_t::number; }
    bool is_bool()       const { return m_type == type_t::boolean; }
    bool is_string()     const { return m_type == type_t::string; }
    bool is_dictionary() const { return m_type == type_t::dictionary; }

    /* ---------- getters (throw if wrong kind) ---------- */
    double              get_number() const { if(!is_number())     throw json_exception{"not a number"};   return m_num; }
    bool                get_bool()   const { if(!is_bool())       throw json_exception{"not a bool"};     return m_bool; }
    std::string const&  get_string() const { if(!is_string())     throw json_exception{"not a string"};   return m_str; }
    auto const&         get_dict()   const { if(!is_dictionary()) throw json_exception{"not a dict"};     return m_dict; }
    auto&               get_dict()         { if(!is_dictionary()) throw json_exception{"not a dict"};     return m_dict; }

    bool contains(std::string const& k) const
    {
        if(!is_dictionary()) return false;
        for(auto const& [key,val] : m_dict) if(key==k) return true;
        return false;
    }

    /* ---------- operator[]  (non‑const) -------------- */
    json& operator[](std::string const& key)
    {
        if(!is_dictionary())
            throw json_exception{"error: operator[] called on non‑dictionary"};

        for(auto& [k,v] : m_dict)
            if(k==key) return v;

        m_dict.push_back({key,{}});          // insert null json
        return m_dict.back().second;
    }

    /* ---------- operator[]  (const) ------------------ */
    json const& operator[](std::string const& key) const
    {
        if(!is_dictionary())
            throw json_exception{"error: operator[] called on non‑dictionary"};

        for(auto const& [k,v] : m_dict)
            if(k==key) return v;

        throw json_exception{"error: searching non‑existing key in const dictionary"};
    }

    /* ---------- operator+= (member) ------------------ */
    json& operator+=(json const& rhs)
    {
        *this = *this + rhs;     // reuse free operator+
        return *this;
    }

    /* ---------- friend operator+ --------------------- */
    friend json operator+(json const& lhs, json const& rhs)
    {
        /* dictionaries → union (keep lhs value on duplicate key) */
        if(lhs.is_dictionary() && rhs.is_dictionary())
        {
            json res = lhs;
            for(auto const& [k,v] : rhs.get_dict())
                if(!res.contains(k))
                    res.get_dict().push_back({k,v});
            return res;
        }

        /* strings → concatenation */
        if(lhs.is_string() && rhs.is_string())
            return json(lhs.get_string() + rhs.get_string());

        /* numbers → arithmetic sum */
        if(lhs.is_number() && rhs.is_number())
            return json(lhs.get_number() + rhs.get_number());

        /* booleans → logical OR */
        if(lhs.is_bool() && rhs.is_bool())
            return json(lhs.get_bool() || rhs.get_bool());

        /* null+null → null */
        if(lhs.is_null() && rhs.is_null())
            return {};

        throw json_exception{"operator+: incompatible json types"};
    }

    /* ---------- quick pretty‑printer ----------------- */
    void print(std::ostream& os = std::cout) const
    {
        switch(m_type)
        {
        case type_t::null:     os << "null"; break;
        case type_t::number:   os << m_num;  break;
        case type_t::boolean:  os << (m_bool? "true":"false"); break;
        case type_t::string:   os << '"' << m_str << '"';      break;
        case type_t::dictionary:
            os << "{ ";
            for(size_t i=0;i<m_dict.size();++i){
                os << '"' << m_dict[i].first << "\": ";
                m_dict[i].second.print(os);
                if(i+1<m_dict.size()) os << ", ";
            }
            os << " }";
            break;
        }
    }
};

/*-----------------------------------------------------------
|  Simple demo
*----------------------------------------------------------*/
int main()
{
    try{
        json cfg;
        cfg["user"] = "alice";
        cfg["debug"] = true;
        cfg["settings"]["volume"] = 5.0;
        cfg["settings"]["theme"]  = "dark";

        json defaults;
        defaults["debug"] = false;
        defaults["settings"]["volume"] = 10.0;

        json merged = cfg + defaults;   // union dictionaries
        merged += json(false);          // bool OR -> keeps existing debug flag

        std::cout << "Merged = ";
        merged.print();
        std::cout << "\n";
    }
    catch(json_exception const& e){
        std::cerr << e.what() << '\n';
    }
}
