#ifndef SINGLETON_HPP
#define SINGLETON_HPP

template<typename T>
class Singleton
{
    public:

        static T*   Get()
        {
            if (!myInstance)
                myInstance = new T();
            return myInstance;
        }

    protected:
        Singleton() {}
        virtual ~Singleton() {}

    private:
        static T*   myInstance;
};

#endif // SINGLETON_HPP
