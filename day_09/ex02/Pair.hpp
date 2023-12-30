#pragma once

class Pair
{
    public: 
            Pair(int nb1, int nb2);
            Pair(const Pair &ref);
            ~Pair();
            Pair &operator=(const Pair &ref);
            
            int small;
            int big;

    private:
            Pair();
};
