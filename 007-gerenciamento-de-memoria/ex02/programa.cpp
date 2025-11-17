#include <iostream>

class vector{
    private:
        int *data;
        unsigned int size_, capacity_, increase_size_;
        void increase_capacity()
        {
            this->capacity_ += this->increase_size_;
            int *new_data = new int[this->capacity_];
            for (int i = 0; i < this->size_; ++i)
                new_data[i] = data[i];
            delete[] this->data;
            this->data = new_data;
        }

    public:
        vector()
        {
            this->size_ = 0;
            this->capacity_ = 100;
            this->increase_size_ = 100;
            this->data = new int[100];
        }
        void push_back(int value)
        {
            if (this->size() == this->capacity())
                increase_capacity();
            this->data[this-> size_++] = value;
        }
        int get_at(int index)
        {
            if (index < 0 or index >= size())
                throw std::out_of_range("Index out of range");
            return this->data[index];
        }
        unsigned int size()
        {
            return this->size_;
        }
        unsigned int capacity()
        {
            return this->capacity_;
        }
        int index_of(int value){
            for (int index = 0; index < size(); index++) 
                if (this->data[index] == value) return index;
            return -1;
        }

        ~vector()
        {
            delete[] this->data;
        }
};
int main(int argc, char **argv)
{
    vector v1;
    int n;
    std::cin >> n;
    while (n != -1)
    {
        std::cout << "Digite um numero: " << std::endl;
        v1.push_back(n);
        std::cin >> n;
    }
    std::cout << "Digite um numero para encontrar: " << std::endl;
    std::cin >> n;
    return 0;
}