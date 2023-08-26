#pragma once

#include <vector>
#include <string>
#include <iostream>

inline double loop_enum_5x(const std::vector<unsigned char>& arr) 
{
    
    std::string combination(5,'\0');
    double combinations = 0;
    for (const auto& a : arr)
    {   
        combination[0] = a;
        combinations++;
        //std::cout << combination;
    }

    for (const auto& a : arr)
    {
        combination[0] = a;
        for (const auto& b : arr)
        {
            combination[1] = b;
            combinations++;
            //std::cout << combination;
        }
    }

    for (const auto& a : arr)
    {
        combination[0] = a;
        for (const auto& b : arr)
        {
            combination[1] = b;
            for (const auto& c : arr)
            {
                combination[2] = c;
                combinations++;
                //std::cout << combination;
            }
        }
    }
    for (const auto& a : arr)
    {
        combination[0] = a;
        for (const auto& b : arr)
        {
            combination[1] = b;
            for (const auto& c : arr)
            {
                combination[2] = c;
                for (const auto& d : arr)
                {
                    combination[3] = d;
                    combinations++;
                    //std::cout << combination;
                }
            }
        }
    }
    for (const auto& a : arr)
    {
        combination[0] = a;
        for (const auto& b : arr)
        {
            combination[1] = b;
            for (const auto& c : arr)
            {
                combination[2] = c;
                for (const auto& d : arr)
                {
                    combination[3] = d;
                    for (const auto& e : arr)
                    {
                        combination[4] = e;
                        combinations++;
                        //std::cout << combination;
                    }
                }
            }
        }
    }
    return combinations;
}

inline double loop_enum_6x(const std::vector<unsigned char>& arr) 
{
    
    std::string combination(6,'\0');
    double combinations = 0;
    for (const auto& a : arr)
    {   
        combination[0] = a;
        combinations++;
        //std::cout << combination;
    }

    for (const auto& a : arr)
    {
        combination[0] = a;
        for (const auto& b : arr)
        {
            combination[1] = b;
            combinations++;
            //std::cout << combination;
        }
    }

    for (const auto& a : arr)
    {
        combination[0] = a;
        for (const auto& b : arr)
        {
            combination[1] = b;
            for (const auto& c : arr)
            {
                combination[2] = c;
                combinations++;
                //std::cout << combination;
            }
        }
    }
    for (const auto& a : arr)
    {
        combination[0] = a;
        for (const auto& b : arr)
        {
            combination[1] = b;
            for (const auto& c : arr)
            {
                combination[2] = c;
                for (const auto& d : arr)
                {
                    combination[3] = d;
                    combinations++;
                    //std::cout << combination;
                }
            }
        }
    }

    for (const auto& a : arr)
    {
        combination[0] = a;
        for (const auto& b : arr)
        {
            combination[1] = b;
            for (const auto& c : arr)
            {
                combination[2] = c;
                for (const auto& d : arr)
                {
                    combination[3] = d;
                    for (const auto& e : arr)
                    {
                        combination[4] = e;
                        combinations++;
                        //std::cout << combination;
                    }
                }
            }
        }
    }

    for (const auto& a : arr)
    {
        combination[0] = a;
        for (const auto& b : arr)
        {
            combination[1] = b;
            for (const auto& c : arr)
            {
                combination[2] = c;
                for (const auto& d : arr)
                {
                    combination[3] = d;
                    for (const auto& e : arr)
                    {
                        combination[4] = e;
                        for (const auto& f : arr)
                        {
                            combination[5] = e;
                            combinations++;
                            //std::cout << combination;
                        }
                    }
                }
            }
        }
    }
    return combinations;
}

