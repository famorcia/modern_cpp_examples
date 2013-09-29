#include <thread>
#include <iostream>
#include <mutex>

using namespace std;

std::mutex g_display_mutex;

void f()
{
    g_display_mutex.lock();
    cerr<<"f piccolo"<<endl;
    g_display_mutex.unlock();
}

struct F {
    void operator()()
    {
        g_display_mutex.lock();
        cerr<<"F GRANDE"<<endl;
        g_display_mutex.unlock();
    }
};

int main()
{
    thread t1(f); // f() executes in separate thread
    F f1;
    thread t2(f1); // F()() executes in separate thread
    t1.join();
    t2.join();
}
