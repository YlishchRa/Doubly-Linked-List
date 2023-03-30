#pragma once

template <typename T>
class List
{
public:
    template <typename T1>
    class Node
    {
    public:
        T1 data;
        Node* ptrNext;
        Node* ptrPriv;

        Node(T1 d = T(), Node* pN = nullptr, Node* pV = nullptr) : data{d}, ptrNext{pN}, ptrPriv{pV} {}
    };

private:
    int size;
    Node<T>* head;
    Node<T>* tail;

public:
    List();
    void push_back(T _data);
    void push_front(T _data);
    void pop_back();
    void pop_front();
    void insert(int place, T _data);
    bool empty();
    T& operator[](int index);
    int getSize() { return size; }
    void clear();
    ~List();
};

template <typename T>
List<T>::List() : head{nullptr}, tail{nullptr}, size{0}
{
}

template <typename T>
void List<T>::push_back(T _data)
{
    if (size == 0)
    {
        head = new Node<T>(_data);
        tail = head;
    }
    else
    {
        tail->ptrNext = new Node<T>(_data, nullptr, tail);
        tail = tail->ptrNext;
    }
    size++;
}

template <typename T>
inline void List<T>::push_front(T _data)
{
    if (size == 0)
    {
        head = new Node<T>(_data);
        tail = head;
    }
    else
    {
        head->ptrPriv = new Node<T>(_data, head, nullptr);
        head = head->ptrPriv;
    }
    size++;
}

template <typename T>
void List<T>::pop_back()
{
    if (empty())
        return;
    // if head is equal to nullptr, it means that this is the end of the list and size = 0
    // so just return method
    // All commited
    if (head == tail)
    {
        delete head;
        tail = nullptr;
    }
    else
    {
        tail = tail->ptrPriv;
        delete tail->ptrNext;
        tail->ptrNext = nullptr;
    }
    size--;
}

template <typename T>
void List<T>::pop_front()
{
    if (empty())
        return;
    if (head == tail)
    {
        delete head;
        tail = nullptr;
    }
    else
    {
        head = head->ptrNext;
        delete head->ptrPriv;
        head->ptrPriv = nullptr;
    }
    size--;
}
template <typename T>
inline void List<T>::insert(int place, T _data)
{
    if (place == 1)
    {
        push_front(_data);
        return;
    }
    if (place > size)
    {
        push_back(_data);
        return;
    }
    Node<T>* currentNode;
    if (place >= size / 2)
    {
        currentNode = tail;
        for (size_t i = size; i > 0; i--)
        {
            if (i == place)
            {
                Node<T>* savedNode = currentNode->ptrPriv;
                currentNode->ptrPriv = new Node<T>(_data, currentNode, currentNode->ptrPriv);
                savedNode->ptrNext = currentNode->ptrPriv;
                size++;
                return;
            }
            currentNode = currentNode->ptrPriv;
        }
    }
    else if (place < size / 2)
    {
        currentNode = head;
        for (size_t i = 1; i < size; i++)
        {
            if (i == place)
            {
                Node<T>* savedNode = currentNode->ptrPriv;
                currentNode->ptrPriv = new Node<T>(_data, currentNode, currentNode->ptrPriv);
                savedNode->ptrNext = currentNode->ptrPriv;
                size++;
                return;
            }
            currentNode = currentNode->ptrNext;
        }
    }
}
template <typename T>
inline bool List<T>::empty()
{
    return size == 0;
}

template <typename T>
T& List<T>::operator[](int index)
{
    Node<T>* current;
    if (index == 0)
    {
        return head->data;
    }
    if (index == size - 1)
    {
        return tail->data;
    }

    current = tail;
    for (size_t i = size - 1; i > 0; i--)
    {
        if (i == index)
        {
            return current->data;
        }
        current = current->ptrPriv;
    }

    return head->data;
}

template <typename T>
inline void List<T>::clear()
{
    while (size)
    {
        pop_back();
    }
}

template <typename T>
inline List<T>::~List()
{
    clear();
}