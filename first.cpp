#include <iostream>
#include <string> // for string class
#include <cmath> // for pow()


// if you need replace types a,b,c by double
float F(float x, float a, float b, float c) {
    float result;

    if(c<0 && b!=0) {
        std::cout << "computing by expression 1\n";
        result = a * (std::pow(x, 2)) + (std::pow(b, 2)) * x; // a * x^2 + b^2 * x
    } else if(c>0 && b==0) {
        std::cout << "computing by expression 2\n";
        result = (x+a) / (x+c);
    } else {
        std::cout << "computing by expression 3\n";
        result = x / c;
    }

    return result;
}

class Val {
    private:
    char type;
    float x; 
    float val_f;
    int val_i;

    public:
    Val() {
        this->type = ' ';
        this->x = 0;
        this->val_f = 0.0f;
        this->val_i = 0;
    }

    Val(char type, float x, float y) {
        this->type = type;
        this->x = x;
        this->val_f = y;
        this->val_i = 0;
    }

    Val(char type, float x, int y) {
        this->type = type;
        this->x = x;
        this->val_i = y;
        this->val_f = 0.0f;
    }

    std::string get_str_val() {
        if (this->type == 'f'){
            return std::to_string(this->val_f);
        }
        if (this->type == 'i'){
            return std::to_string(this->val_i);
        }

        return "NaN";
    }

    float get_x() {
        return this->x;
    }

    std::string get_info() {
        return "x:" + std::to_string(this->x) + "\ty:" + (this->get_str_val());
    }
};

class Table {
    public:
    Val *vals;
    int size;

    Table(int size) {
        this->size = size;
        this->vals = new Val[size];
    }

    ~Table() {
        delete[] this->vals;
    }

    void printself() {
        std::cout << "i:\tx:\ty\n";
        for (int i=0; i < this->size; i++) {
            std::string y = this->vals[i].get_str_val();
            std::cout << i << ":\t" << vals[i].get_x() << ":\t" << y << '\n';
        }
    }

    void set_row(int i, float x, int y){
        this->vals[i] = Val('i', x, y);
    }

    void set_row(int i, float x, float y){
        this->vals[i] = Val('f', x, y);
    }
};


int main() {
    float a,b,c; // replacable type
    float start, end, step; // suppose int

    std::cout << "enter a: "; std::cin >> a;
    std::cout << "enter b: "; std::cin >> b;
    std::cout << "enter c: "; std::cin >> c; std::cout << '\n';

    std::cout << "enter start value: "; std::cin >> start; 
    std::cout << "enter end value: "; std::cin >> end; 
    std::cout << "enter step: "; std::cin >> step; std::cout << '\n';

    int table_size = (int)(end-start/step);
    std::cout << "table_size: " << table_size << '\n';

    Table table = Table(table_size+1);

    for (int i=0; i<=table_size; i++) {
        int a_int=(int)a, b_int=(int)b, c_int=(int)c;

        float x = start + (step * i);
        float y = F(x, a, b, c);

        if (((a_int & b_int) | (a_int & c_int)) == 0) {
            table.set_row(i, x, (int)y);
        } else {
            table.set_row(i, x, y);
        }
    }

    table.printself();
}
