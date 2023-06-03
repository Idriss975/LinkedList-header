#include <array>
#include <stdexcept>

template <typename T, unsigned int Length>
class linkedTable
{
private:
    unsigned int size;
    struct linkedNode
    {
        public:
        T value;
        linkedNode *Next = nullptr;
    };
    linkedNode *Start = new linkedNode;

public:
    linkedTable();
    linkedTable(std::array<T,Length>);
    T operator[](const unsigned int);
    void push_back(const T);
    ~linkedTable();
};


template <typename T, unsigned int Length>
linkedTable<T, Length>::linkedTable()
{
    size = Length;
    linkedNode *temp = Start;
    for (size_t i = 0; i < Length; i++)
    {
        temp -> value = 0;
        if (i < Length - 1)
        {
            temp -> Next = new linkedNode;
            temp = temp -> Next;
        }
    }
}

template <typename T, unsigned int Length>
linkedTable<T, Length>::linkedTable(std::array<T,Length> Values)
{
    if(Values.size() == 0)
        throw std::invalid_argument("Length of array argument is zero.");
    if (Length != Values.size())
        throw std::invalid_argument("Length of argument is not the same size of Length attribute");
    
    size = Length;
    linkedNode *temp = Start;
    for (unsigned int i = 0; i < Length; i++)
    {
        temp -> value = Values.at(i);
        if (i < Length - 1)
        {
            temp -> Next = new linkedNode;
            temp = temp -> Next;
        }
    }
}

template <typename T, unsigned int Length>
T linkedTable<T, Length>::operator[](const unsigned int i)
{
    if (i > size-1)
        throw std::invalid_argument("argument value bypasses length of the list.");

    linkedNode *temp = Start;
    for (unsigned int ind = 0; ind < i; ind++)
        temp = temp -> Next;
    return temp->value;
}

template <typename T, unsigned int Length>
void linkedTable<T, Length>::push_back(const T val)
{
    linkedNode *temp = Start;
    for (size_t i = 0; i < size - 1; i++)
        temp = temp -> Next;
    
    temp -> Next = new linkedNode;
    temp = temp -> Next;
    temp -> value = val;

    size++;
}

template <typename T, unsigned int Length>
linkedTable<T, Length>::~linkedTable()
{
    std::array<linkedNode*,Length> addr;
    linkedNode *temp = Start;
    for (unsigned int i = 0; i < Length; i++)
    {
        addr.at(i) = temp;
        temp = temp -> Next;
    }

    for (unsigned int i = addr.size()-1; i > 0; i--)
    {
        delete addr.at(i);
        addr.at(i) = nullptr;
    } 
}