template <typename T>
class my_container {
    T value;
public:
    my_container(T v) : value(v) {}
    void increment() { ++value; }   // works if T supports ++
    T  get() const { return value; }
};
