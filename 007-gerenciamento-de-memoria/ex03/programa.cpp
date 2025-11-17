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
        void decrease_capacity()
        {
            this->capacity_ -= this->increase_size_;
            int *new_data = new int[this->capacity_];
            for (int i = 0; i < this->size_; ++i)
                new_data[i] = data[i];
            delete[] this->data;
            this->data = new_data;
        }

        void reorganize_at(unsigned int index){
            unsigned int new_size = this->size_ - 1;
            for (unsigned int i = index + 1; i < this->size_; i++) this->data[i-1] = this->data[i];
            this->size_ = new_size;
            if (this->capacity_ - this->increase_size_  >= this->size_) this->decrease_capacity();
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
            this->data[this->size_++] = value;
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

        bool remove(int value){
            for (unsigned int index = 0; index < this->size(); index++) {
                if (this->data[index] == value) {
                    this->reorganize_at(index);
                    return true;
                }
            } 
            return false;
        }
        bool remove_at(int index){
            if (index >= 0 && index < this->size()){
                this->reorganize_at(index);
                return true;
            }
            return false;
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