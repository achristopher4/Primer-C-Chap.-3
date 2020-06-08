//
//  main.cpp
//  3.4 to 3.6
//
//  Created by Alex Christopher on 5/29/20.
//  Copyright © 2020 Alex Christopher. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <cstddef>
#include "string.h"

using std::cin; using std::cout; using std::endl;
using std::string; using std::vector;

int main(){
    //3.4.1
    // the compiler determines the type of b and e
    // b denotes the first element and e denotes one past the last element in v
    // auto b = v.begin(), e = v.end(); // b and e have the same type
    string s("some string");
    if (s.begin() != s.end()) { // make sure s is not empty
        auto it = s.begin(); // it denotes the first character in s
        *it = toupper(*it); // make that character uppercase
    }
    cout << s << endl;
    
    // process characters in s until we run out of characters pr we hit a whitespace
    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
        *it = toupper(*it); // capitalize the current character
    cout << s << endl;
    
    // iterator Types
    vector<int>::iterator it; // it can read and write vector<int> elements
    string::iterator it2; // it2 can read and write characters in a string
    vector<int>::const_iterator it3; // it3 can read but not write elements
    string::const_iterator it4; // it4 can read but not write characters
    
    //
    //text must be sorted
    // beg and end will denote the range we're searching
    vector<string> text{"A", "B", "C", "D", "E", "F"};
    auto beg = text.begin(), end = text.end();
    auto mid = text.begin() + (end - beg)/2; //orginal midpoint
    // while there are still elements to look at and we haven't yet found sought
    string sought = "B";
    while (mid != end && *mid != sought) {
        if (sought < *mid) // is the element in the first half
            end = mid; // if so readjust the range
        else
            beg = mid + 1; // start looking for element after mid
        mid = beg + (end - beg)/2; // new mid point
    }
    
    
    // 3.5 Arrays
    constexpr unsigned sz = 42; // constant expression
    int arr[10]; // array of ten ints
    int *parr[sz]; // array of 42 pointers to int
    string strs[/* fucntion_name() */ sz]; // ok if function_name() is a constexpr, error otherwise
    // Explicitly initializing
    const unsigned sz2 = 3;
    int ial[sz2] = {0, 1, 2}; // array of three ints with values 0, 1, 2
    int a2[] = {0, 1, 2}; // an array of dimension 3
    int a3[5] = {0, 1, 2}; // equal to a3[] = {0, 1, 2, 0, 0}
    string a4[3] = {"Hello", "Bye"}; // same as a4[] = {"hi", "bye", ""}
    //character array
    char ca1[] = {'C', '+', '+'}; //list initialization, no null
    char ca2[] = {'C', '+', '+', '\0'}; // list initialization, explicitly null
    char ca3[] = "C++"; // null terminator added automatically
    const char ca4[7] = "Daniel"; // if 6 in brackets, error would occur
    // Cannot initialize an array of another array, nor assign one array to another
    //Complicated Array Declarations
    int *ptrs[10]; // ptrs is an array of ten pointers to int
    // cannot have arrays of reference
    int (*parray)[10] = &arr; //parray points to an array of ten ints
    int (&arrRef)[10] = arr;  // arrRef refers to an array of ten ints
    int *(&arry)[10] = ptrs; // arry is a refernce to an array of ten pointers to ints
    
    //3.5.2
    // count the number of grades by cluster of ten
    unsigned scores [11] = {}; // 11 buckets, all values initialized to 0
    unsigned grade;
    while (cin >> grade) {
        if (grade <= 100)
            ++scores[grade/10]; //increment the counter for the current cluster
        else
            break;
    }
    for (auto &i : scores)
        cout << i << " ";
    cout << endl;
    
    // 3.5.3 pointers to arrays
    string nums[] = {"One", "Two", "Three"}; // an array of strings
    string *p = &nums[0];  // p points to the first elements in nums
    string *p2 = nums;  // equivalent to p2 = &nums[0]
    int ia [] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // ia is an array of ten ints
    auto ia2(ia); // ia2 is an int* that points to the first elements in ia
    auto ia3(&ia[0]);  // ia2 has type int*
    //making an array of ten ints using decltype
    decltype(ia) ia4 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i;
    ia3[4] = i; // ok: assigns the value of i to an element in ia3
    // Library begin and end functions
    // pbeg points to the first element and pend points just past the last element in ia
    int *pbeg = std::begin(ia);
    int *pend = std::end(ia);
    // find the first negative element, stopping if we've seen all the elements
    while (pbeg != pend && *pbeg >= 0)
        ++pbeg;
    //pointer arithmetic
    constexpr size_t sz3 = 5;
    int arr3[sz3] = {1, 2, 3, 4, 5};
    int *ip = arr3; // equivalent to int *ip = &arr[0]
    int *ip2 = ip + 4; // ip2 points to arr[4], the last element in arr
        // adding an intergal value to a pointer
    int *pp2 = arr3 + sz3; // use caution -- don't dereference
        // subtraction
    auto n = std::end(arr3) - std::begin(arr3); // n is 5, the number of elements in arr
        // using relational operators to compare pointers that point to elements of an array
    int *b = arr3, *e = arr3 + sz3;
    while (b < e) {
        // use *b
        ++b;
    }
    //Interactions between dereference and pointer arithmetic
    int iia2[] = {0, 2, 4, 6, 8}; // array with 5 elements o type int
    int last = *(iia2 + 4); // ok: initializes last to 8, the value of ia[4]
    int last2 = *iia2 + 4; // ok: last = 4, equivalent to ia2[0] + 4
    // Subsripts and Pointers
    int ii = iia2[2]; // ia is converted to a pointer to the first element in ia,
                    // ia[2] fetches the element to which (ia + 2) points
    int *sp = iia2; // sp points to the first element in ia
    ii = *(sp +2); // equal to i = ia[2]
    int *sp2 = &iia2[2]; // sp points to the element indexed by 2
                        // p[1] os equivalent to *(p + 1), sp[1] os the same as ia[3]
    int k = sp[-2]; // sp[-2] is the same element as ia[0]
    
    // 3.5.4 C-Style Character String
    //comparing strings
    string s1 = "A string example";
    string s2 = "A different string";
        // s2 is less than s1
    const char cca1[] = "A string example";
    const char cca2[] = "A different string";
    if (strcmp(cca1, cca2) < 0){    // same effect as comparing string s1 and s2
        cout << "hello" << endl;
    }
    // caller is responisble
    //initialize largerStr as a concatenation of s1, spacpe, and s2
    string largeStr = s1 + " " + s2;
    // use strcat and strcpy fpr array
    // diasterous of miscalucalulated
    char largerstr[100] ;
    std::strcpy(largerstr, cca1);   // copies cca1 into largeStr
    std::strcat(largerstr, " ");      // adds a space at the end of largerstr
    std::strcat(largerstr, cca2);     // concatenates cca2 onto largerstr
    
    // 3.5.5 Interfacing to Older Code
    // mix library
    string sss("Hello"); //s holds hello
    const char *str = sss.c_str();
    //Using an array to initialize a vector
    int int_arr[] = {1, 2, 3, 4, 5};
    // ivec has six elements; each a copy of the corresponding element in int_arr
    vector<int> ivec(std::begin(int_arr), std::end(int_arr));
    //specify the range
    vector<int> subVec(int_arr + 1, int_arr + 4);
    
    
    //3.6 Multidimensional Arrays
    // Initializing the elements of a multidimensional array
    int mda[3][4] = { // three elements; each element is an array of size 4
        {0, 1, 2, 3},   // initializers for the row indexed by 0
        {4, 5, 6, 7},   // inititalizers for the row indexed by 1
        {8, 9, 10, 11}  // inittializers for the row indexed by 2
    };
    int mda2[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; // same as mda[3][4]
    //explicitly initialize only element 0 in each row
    int mda3[3][4] = {{0}, {4}, {8}};
    //explicitly initialize row 0; the remaining elements are value intialized
    int mda4[3][4] = {0, 3, 6, 9};
    
    // Subscripting a multidimensional array
    mda2[2][3] = mda[0][0];// assigns the first element of arr to the last element in the last row of ia
    int (&row)[4] = mda3[1]; // binds row to the second four-element array in ia
    //example two
    constexpr size_t rowCnt = 3, colCnt = 4;
    int mda6[rowCnt][colCnt]; // 12 uninitialized elements
    //for each row
    for (size_t i = 0; i != rowCnt; ++i){
        // for each column within the row
        for (size_t j = 0; j != colCnt; ++j) {
            // assign the element's positional index as its value
            mda6[i][j] = i * colCnt + j;
        }
    }
    
    // Using a Range for with Multidimensional Arrays
    size_t cnt = 0;
    for (auto &row : mda3){     // for every element in the outer array
        for (auto &col : row){  // for every element in the inner array
            col = cnt;          // give this element the next value
            ++cnt;              // increment cnt
        }
    }
    for (const auto &row : mda3){
        for (auto col : row){
            cout << col << endl;
        }
    }
    
    // Pointers and Multidimensional Arrays
    int mda7[3][4]; // array of size 3; each element is array of ints of size 4
    int (*pmda)[4] = mda7; // p points to an array of four ints
    pmda = &mda7[2]; // p now points to the last element in mda7
    //print the value of each element in mda7, with each inner array on its own line
    // p points to an array of four ints
    for (auto p = mda7; p != mda7 + 3; ++p){
        // q points to the first element of an array of four ints; that is, q points to an int
        for (auto q = *p; q != *p + 4; ++q){
            cout << *q << ' ';
        }
        cout << endl;
    }
    // same loop as previous exmaple, but using begin and end fucntions
    for (auto p = std::begin(mda7); p != std::end(mda7); ++p){
        for (auto q = std::begin(*p); q != *p; ++q){
            cout << *q << ' ';
        }
        cout << endl;
    }
    
    // Type Aliases Simplify Pointers to Multidimensional Arrays
    using int_array2 = int[4]; // new style type alias declaration
    typedef int int_array2[4]; // equivalent to typedef declaration
    // print the value of each element in ia with each inner array on its own line
    for (int_array2 *p = mda7; p != mda7 + 3; ++p){
        for (int *q = *p; q != *p + 4; ++q){
            cout << *q << ' ';
        }
        cout << endl;
    }
    
    
    return 0;
}
