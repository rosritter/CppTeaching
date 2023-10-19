#include <gtest/gtest.h>
#include "imNumbers.hpp"
#include "cstack.hpp"
#include <iostream>
#include <string>
#include <cstdint>


// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions)
{
    EXPECT_STRNE("hello", "world");
}


// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions0)
{
    // Expect two strings not to be equal.
    ImNumber<int> num;
    EXPECT_STRNE("hello", "world");
    ImNumber<double> num1(1, 2);
    ImNumber<double> num2(1, 2);
    EXPECT_EQ(num1, num2);
}

TEST(HelloTest, BasicAssertions1)
{
    ImNumber<float> num(1, 2);
    EXPECT_EQ(num == ImNumber<float>(1, 2), true);
}

TEST(HelloTest, BasicAssertions2)
{
    ImNumber<int> num(1, 2);
    num = num + ImNumber<int>(0, 500);
    EXPECT_EQ(num, ImNumber<int>(1, 502));
    ImNumber<int> num1 = (1, 2);
    num1 = num1 + ImNumber<int>(500, 0);
    EXPECT_EQ(num1, ImNumber<int>(501, 2));
}

TEST(HelloTest, BasicAssertions3)
{
    ImNumber<int> num(1, 2);
    num = num - ImNumber<int>(0, 500);
    EXPECT_EQ(num, ImNumber<int>(1, -498));
     ImNumber<int> num1(1, 2);
    num1 = num1 - ImNumber<int>(500, 0);
    EXPECT_EQ(num1, ImNumber<int>(-499, 2));
}

TEST(HelloTest, BasicAssertions5)
{
    ImNumber<double> n1(-9, -7);
    ImNumber<double> n2(-1, 1);
    auto n3 = n1 * n2;
    EXPECT_EQ(n3, ImNumber<double>(16, -2));
}

TEST(HelloTest, BasicAssertions6)
{
    ImNumber<float> n1(-9, -7);
    ImNumber<float> n2(1, 1);
    auto n3 = n1 / n2;
    EXPECT_EQ(n3, ImNumber<float>(1, 8));
}

TEST(HelloTest, BasicAssertions7)
{
    ImNumber<int> num(1, 2);
    num += ImNumber<int>(0, 500);
    EXPECT_EQ(num, ImNumber<int>(1, 502));
    
    ImNumber<unsigned int> num1(1, 2);
    num1 += ImNumber<unsigned int>(500, 0);
    EXPECT_EQ(num1, ImNumber<unsigned int>(501, 2));
}

TEST(HelloTest, BasicAssertions8)
{
    auto num = ImNumber<int>(1, 2);
    num -= ImNumber<int>(0, 500);
    EXPECT_EQ(num, ImNumber<int>(1, -498));

    ImNumber<short int> num1(1, 2);
    num1 -= ImNumber<short int>(500, 0);
    EXPECT_EQ(num1, ImNumber<short int>(-499, 2));
}

TEST(HelloTest, BasicAssertions10)
{
    ImNumber<double> n1(-9, -7);
    ImNumber<double> n2(-1, 1);
    n1 *= n2;
    EXPECT_EQ(n1, ImNumber<double>(16, -2));
}

TEST(HelloTest, BasicAssertions11)
{
    ImNumber<double> n1(-9, -7);
    ImNumber<double> n2(-1, 1);
    n1 /= n2;
    EXPECT_EQ(n1, ImNumber<double>(1, 8));
}

TEST(HelloTest, BasicAssertions12)
{
    ImNumber<float> num(0,0);
    EXPECT_EQ(num, ImNumber<float>());
}

TEST(HelloTest, BasicAssertions13)
{
    ImNumber<double> num(3,-4);
    EXPECT_EQ(num(), 5);
}

TEST(HelloTest, BasicAssertions14)
{
    ImNumber<double> num(3,4);
    EXPECT_EQ(num(), 5);
}

TEST(HelloTest, BasicAssertions15)
{
    ImNumber<float> num(3,4);
    EXPECT_EQ(!num, ImNumber<float>(3,-4));
}


TEST(HelloTest, BasicAssertions16)
{
    ImNumber<double> num(3,0);
    EXPECT_EQ(!num, ImNumber<double>(3,0));
}


TEST(HelloTest, BasicAssertions17)
{
    ImNumber<double> num(3,4);
    EXPECT_EQ(num(), 5);
}


TEST(HelloTest, BasicAssertions18)
{
    ImNumber<double> n1(3,4);
    ImNumber<double> n2(3,-4);
    EXPECT_EQ(n1 < n2, false);
}

TEST(HelloTest, BasicAssertions19)
{
    ImNumber<float> n1(3,4);
    ImNumber<float> n2(0,0);
    EXPECT_EQ(n1 < n2, false);
}

TEST(HelloTest, BasicAssertions20)
{
    ImNumber<double> n1(3,4);
    ImNumber<double> n2(0,0);
    EXPECT_EQ(n2 < n1, true);
}

TEST(HelloTest, BasicAssertions21)
{

    ImNumber<double> n1(3,4);
    ImNumber<double> n2(3,-4);
    testing::internal::CaptureStdout();
    std::cout << n1 << ' ' << n2;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, std::string("3+i4 3-i4"));
}


// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions4) {
    // Expect two strings not to be equal.
    CStack<std::string> stack;
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(stack.empty(), true);
}

TEST(HelloTest, BasicAssertions9) {
    // Expect two strings not to be equal.
    using namespace std;
    stack<uint32_t> s;
    CStack<uint32_t> cs;

    cs.pop();
    for(size_t i = 0; i < 10000; i++){
        EXPECT_EQ(s.empty(), cs.empty());
        if (!s.empty())
            EXPECT_EQ(s.top(), cs.top());
        int r = rand() % 255;
        if(r % 2 == 0){
            s.push(r);
            cs.push(r);
        }        
        else if (!s.empty()){
            s.pop();
            cs.pop();
        }
    }
}


TEST(HelloTest, BasicAssertions22) {
    // Expect two strings not to be equal.
    using namespace std;
    stack<double> s;
    Cstack<double> cs;

    cs.pop();

    for(size_t i = 0; i < 500; i++){
        EXPECT_EQ(s.empty(), cs.empty());
        if (!s.empty())
            EXPECT_EQ(s.top(), cs.top());
            double r = double(rand() % 255) / 10;
            s.push(r);
            cs.push(r);      
    }
    for(size_t i = 0; i < 5000; i++){
        EXPECT_EQ(s.empty(), cs.empty());
        if (!s.empty())
            EXPECT_EQ(s.top(), cs.top());
        
        double r = double(rand() % 255) / 100;
        if(rand() % 2 == 0){
            s.push(r);
            cs.push(r);
        }        
        else if (!s.empty()){
            s.pop();
            cs.pop();
        }
    }
}

TEST(HelloTest, BasicAssertions23) {
    // Expect two strings not to be equal.
    using namespace std;
    stack<char> s;
    CStack<char> cs;

    cs.pop();

    for(size_t i = 0; i < 500; i++){
        EXPECT_EQ(s.empty(), cs.empty());
        if (!s.empty())
            EXPECT_EQ(s.top(), cs.top());
            char r = rand() % 127;
            s.push(r);
            cs.push(r);      
    }
    for(size_t i = 0; i < 5000; i++){
        EXPECT_EQ(s.empty(), cs.empty());
        if (!s.empty())
            EXPECT_EQ(s.top(), cs.top());
        char r = rand() % 255;
       
        if(rand() % 2 == 0){
            s.push(r);
            cs.push(r);
        }        
        else if (!s.empty()){
            s.pop();
            cs.pop();
        }
    }
}

TEST(HelloTest, BasicAssertions24) {
    // Expect two strings not to be equal.
    using namespace std;
    stack<float> s;
    CStack<float> cs;
    cs.pop();

    for(size_t i = 0; i < 500; i++){
        float r = float(rand() % 255)/10;
        s.push(r);
        cs.push(r);      
    }
    float mul = 5.5;
    cs *= mul;
    for(size_t i = 0; i < 500; i++){
        if (!s.empty()&&!cs.empty()){
            EXPECT_EQ(mul * s.top(), cs.top());
            s.pop();
            cs.pop();
        }
    }
}


TEST(HelloTest, BasicAssertions25) {
    // Expect two strings not to be equal.
    using namespace std;
    stack<uint32_t> s;
    CStack<uint32_t> cs;
    cs.pop();

    for(size_t i = 0; i < 500; i++){
        uint32_t r = rand() % 255;
        s.push(r);
        cs.push(r);      
    }
    auto cs1 = cs;
    for(size_t i = 0; i < 5000; i++){
        if (!s.empty()&&!cs1.empty()){
            EXPECT_EQ(s.top(), cs1.top());
            s.pop();
            cs1.pop();
        }
    }
}


TEST(HelloTest, BasicAssertions26) {
    // Expect two strings not to be equal.
    using namespace std;
    vector<double> v;
    vector<Node<double>> v1;
    size_t elems = 500;
    for(size_t i = 0; i < elems; i++){
        double r = double(rand() % 255) / 100;
        v.push_back(r);
        Node<double> n;
        n.info = r;
        v1.push_back(n);
    }
    sort(v.begin(),v.end());
    sort(v1.begin(),v1.end());  
}