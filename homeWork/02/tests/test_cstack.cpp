#include <gtest/gtest.h>
#include "cstack.hpp"
#include <stack>
#include <random>
#include <vector>
#include <algorithm>


// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
    EXPECT_STRNE("hello", "world");
}


// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions0) {
    // Expect two strings not to be equal.
    auto stack = CStack();
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(stack.empty(), true);
}

TEST(HelloTest, BasicAssertions1) {
    // Expect two strings not to be equal.
    using namespace std;
    stack<uint32_t> s;
    auto cs = CStack();

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


TEST(HelloTest, BasicAssertions2) {
    // Expect two strings not to be equal.
    using namespace std;
    stack<uint32_t> s;
    auto cs = CStack();

    cs.pop();

    for(size_t i = 0; i < 500; i++){
        EXPECT_EQ(s.empty(), cs.empty());
        if (!s.empty())
            EXPECT_EQ(s.top(), cs.top());
        int r = rand() % 255;

            s.push(r);
            cs.push(r);      
    }
    for(size_t i = 0; i < 5000; i++){
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

TEST(HelloTest, BasicAssertions3) {
    // Expect two strings not to be equal.
    using namespace std;
    stack<uint32_t> s;
    auto cs = CStack();

    cs.pop();

    for(size_t i = 0; i < 500; i++){
        EXPECT_EQ(s.empty(), cs.empty());
        if (!s.empty())
            EXPECT_EQ(s.top(), cs.top());
        int r = rand() % 255;

            s.push(r);
            cs.push(r);      
    }
    for(size_t i = 0; i < 5000; i++){
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

//* = [] <
TEST(HelloTest, BasicAssertions4) {
    // Expect two strings not to be equal.
    using namespace std;
    vector<uint32_t> v;
    auto cs = CStack();
    cs.pop();

    for(size_t i = 0; i < 500; i++){
        int r = rand() % 255;
        v.push_back(r);
        cs.push(r);
        for(size_t j = i; j > 0; j--){
            EXPECT_EQ(v[j], cs[j]);
        }
    }
}



TEST(HelloTest, BasicAssertions5) {
    // Expect two strings not to be equal.
    using namespace std;
    stack<uint32_t> s;
    auto cs = CStack();
    cs.pop();

    for(size_t i = 0; i < 500; i++){
        int r = rand() % 255;
        s.push(r);
        cs.push(r);      
    }
    int mul = 5;
    cs *= mul;
    for(size_t i = 0; i < 5000; i++){
        if (!s.empty()&&!cs.empty()){
            EXPECT_EQ(mul * s.top(), cs.top());
            s.pop();
            cs.pop();
        }
    }
}


TEST(HelloTest, BasicAssertions6) {
    // Expect two strings not to be equal.
    using namespace std;
    stack<uint32_t> s;
    auto cs = CStack();
    cs.pop();

    for(size_t i = 0; i < 500; i++){
        int r = rand() % 255;
        s.push(r);
        cs.push(r);      
    }
    CStack cs1 = cs;
    for(size_t i = 0; i < 5000; i++){
        if (!s.empty()&&!cs1.empty()){
            EXPECT_EQ(s.top(), cs1.top());
            s.pop();
            cs1.pop();
        }
    }
}


TEST(HelloTest, BasicAssertions7) {
    // Expect two strings not to be equal.
    using namespace std;
    vector<uint32_t> v;
    vector<Node> v1;
    size_t elems = 500;
    for(size_t i = 0; i < elems; i++){
        int r = rand() % 255;
        v.push_back(r);
        Node n;
        n.info = r;
        v1.push_back(n);
    }
    sort(v.begin(),v.end());
    sort(v1.begin(),v1.end());  
}