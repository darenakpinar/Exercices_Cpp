#include <iostream>
#include <string>
// ex is remove all elements equeal to the given parameter e

// void listdl:: remove_all(int e)

class listdl{

    private:
        struct celldl{
            int info;
            celldl *next;
            celldl *prev;
        }
        celldl *head;
        celldl*tail;

    public:
        void remove_all(ine e)

};

        void listdl::remove_all(int e){
            celldl * pc = head;
            while (pc){
                if (pc->info == 'e'){
                    if (pc->next && pc->prev){
                        pc->prev->next = pc->next;
                        pc->next->prev = pc->prev;
                    }
                    else if (!pc->prev && pc->next){
                        pc->next->prev= nullptr;
                        head = pc->next;
                    }
                    else if (pc->prev && !pc->next){
                        pc->prev->next = nullptr;
                        tail = pc->prev;
                    }
                    else { // pc is the only element
                        head= tail=nullptr;
                    }
                    celldl * d = pc;
                    pc = pc->next;
                    delete d;
                }
            else {
                pc = pc->next;
            }
            }
        }

