```cpp
void decrease_capacity()
{
    this->capacity_ -= this->increase_size_;
    int *new_data = new int[this->capacity_];
    for (int i = 0; i < this->size_; ++i)
        new_data[i] = data[i];
    delete[] this->data;
    this->data = new_data;
}
```
> calculo
### Complexidade:
```cpp
void reorganize_at(unsigned int index){
    unsigned int new_size = this->size_ - 1;
    for (unsigned int i = index + 1; i < this->size_; i++) this->data[i-1] = this->data[i];
    this->size_ = new_size;
    if (this->capacity_ - this->increase_size_  >= this->size_) this->decrease_capacity();
}
```
> calculo
### Complexidade:
```cpp
bool remove(int value){
    for (unsigned int index = 0; index < this->size(); index++) {
        if (this->data[index] == value) {
            this->reorganize_at(index);
            return true;
        }
    } 
    return false;
}
```
> calculo
### Complexidade:
```cpp
bool remove_at(int index){
    if (index >= 0 && index < this->size()){
        this->reorganize_at(index);
        return true;
    }
    return false;
}
```
> calculo
### Complexidade:
