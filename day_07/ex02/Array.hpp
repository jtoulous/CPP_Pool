#pragma once

#include <cstdlib>
#include "String_2_guerre.hpp"

template <typename T>
class Array
{
    public:
///////////        BUILDERS, Etc ////////////////      
      
            Array<T>()
            : array(NULL), len (0)
            {}
            
            Array<T>(unsigned int in_size)
            : array(new T[in_size]), len(in_size)
            {};
            
            Array<T>(const Array &ref)
            : array(NULL)
            {
                if (&ref != this)
                        this = ref;
            }

            ~Array<T>()
            {
                if (array != NULL)
                        delete[] array;
            }


///////           OPERATORZ            //////

            Array<T>   &operator=(const Array &ref)
            {
                if (this != &ref)
                {
                        if (array != NULL)
                                delete[] array;
                        array = new T[ref.size()];
                        for (unsigned int z = 0; z < ref.size(); z++)
                        array[z] = ref.array[z];
                        len = ref.size();
                }
                return (*this);
            }

            
            T   &operator[](unsigned int index)
            {
                String  tmp;  

                if (index >= this->size())
                {
                        tmp = "index ";
                        tmp.push_back(index + '0');
                        tmp += ", is superior to the size of the array";
                        throw (Xception(tmp));
                }
                return (array[index]);
            }

//               FUNCZ                   ////

            unsigned int size() const
            {
                return (len);
            }

////////////////////////////////////////////////////////////////

    private:
            T            *array;
            unsigned int len;
};