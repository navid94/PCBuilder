#ifndef CONTAINER_H
#define CONTAINER_H

template<class T>
class Container{
    friend class Iterator;
private:
    class nodo;
    class smartp{
    public:
        nodo* punt;
        smartp(nodo* p=0):punt(p){
            if (punt)
                punt->riferimenti++;
        }

        smartp(const smartp& s):punt(s.punt){
            if (punt)
                punt->riferimenti++;
        }
        ~smartp(){
            if (punt){
                punt->riferimenti--;
                if (punt->riferimenti==0)
                    delete punt;
            }
        }
        smartp& operator=(const smartp& s){
            if (this!=&s){
                nodo* t=punt;
                punt=s.punt;
                if (punt)
                    punt->riferimenti++;
                if (t){
                    t->riferimenti--;
                    if (t->riferimenti==0)
                        delete t;
                }
            }
            return *this;
        }
        nodo& operator*() const{
            return *punt;
        }
        nodo* operator->() const{
            return punt;
        }
        bool operator==(const smartp& s) const{
            return punt==s.punt;
        }
        bool operator!=(const smartp& s) const{
            return punt!=s.punt;
        }
    };
    class nodo{
    public:
        nodo(T i,const smartp& n=0):info(i),next(n),riferimenti(0){}
        T info;
        smartp next;
        int riferimenti;
    };
    smartp first;
public:
    class iteratore{
        friend class Container;
    private:
        Container::smartp it_pointer;
    public:
        bool operator==(iteratore it) const{
            return it_pointer==it.it_pointer;
        }
        bool operator!=(iteratore it) const{
            return it_pointer!=it.it_pointer;
        }
        iteratore& operator++(){
            if (it_pointer.punt)
                it_pointer=it_pointer->next;
            return *this;
        }

        iteratore operator++(int){
            iteratore aux=*this;
            if (it_pointer.punt)
                it_pointer=it_pointer->next;
            return aux;
        }
    };
    Container():first(0){}
    bool Vuota() const{
        return first==0;
    }
    void aggiungi_elemento(T e){
        first=new nodo(e,first);
    }
    void rimuovi_elemento(T u){
        smartp p=first, prec, q;
        smartp original=first;
        first=0;
        while (p!=0 && !(p->info==u)){
            q=new nodo(p->info,p->next);
            if (prec==0)
                first=q;
            else
                prec->next=q;
            prec=q;
            p=p->next;
        }
        if (p==0)
            first=original;
        else
        {
            if (prec==0)
                first=p->next;
            else
                prec->next=p->next;
        }
    }

    iteratore begin() const{
        iteratore aux;
        aux.it_pointer=first;
        return aux;
    }
    iteratore end() const{
        iteratore aux;
        aux.it_pointer=0;
        return aux;
    }
    T& operator[](iteratore it) const{
        return (it.it_pointer)->info;
    }
};

#endif // CONTAINER_H
