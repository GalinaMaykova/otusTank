#pragma once

#include <queue>
#include <mutex>

template <class T>
class myTqueue
{
public:

    bool pop(T& element)
    {
        std::lock_guard<std::mutex> lk(mtx);
        if (m_queue.empty())
        {
            return false;
        }
        element = m_queue.front(); 
        m_queue.pop();
        return true;
    }

    void push(const T& value)
    {
        std::lock_guard<std::mutex> lk(mtx);
        m_queue.push(value);
    }

private:
    std::mutex mtx;
    std::queue<T> m_queue;
};