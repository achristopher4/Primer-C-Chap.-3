//
//  main.cpp
//  3.1 to 3.3
//
//  Created by Alex Christopher on 5/24/20.
//  Copyright © 2020 Alex Christopher. All rights reserved.
//

#include <iostream>
//include string header
#include <string>
#include <cctype>
#include <vector>

//3.1 using declaration; when we use the name cin, we get the one from the namespace std
using std::cin;
//using declarations for names from the standard library
using std::cout; using std::endl;
//using declarationf for string
using std::string; using std::vector;

//int main() {
//    int i;
//    cin >> i; // ok: cin is a synonym for std::cin
//    std::cout << i; // ok: explicity use cout from namespace std
//    return 0;
//}

int main() {
//    cout << "enter two numbers:" << endl;
//    int v1, v2;
//    cin >> v1 >> v2;
//    cout << "The sum of " << v1 << " and " << v2 << " is "
//    << v1 + v2 << endl;
//    return 0;
    
    //3.2.1
    // initializing a string
    string s1; // Default initialization; s1 is an empty string
    string s2(s1); // s2 is a copy of s1
    string s3 = s1; // Equivalent to s2(s1), s3 is a copy of s1
    string s4 ("Value"); // s4 is a copy of the string literal, not including the null
    string s5 = "value"; // Equivalent to s4, s5 is a copy of the string literal
    string s6(10, 'c'); // Initialize s6 with n copies of the character 'c'
    cout << s4 << " " << s6 << endl;
    // copy vs. direct form
    string s7 = "Hello"; // copy initialization
    string s8("Hello"); // direct initialization
    string s9(15, 'a'); // direct initialization
    string s10 = string(10, 'a'); // copy initialization, s10 is cccccccccc
    
    //3.2.2.
    // Reading and writing strings
//    string ss1, ss2; //empty string
//    cin >> ss1 >> ss2; // read whitespace-separated string into s
//    cout << ss1 << " " << ss2 << endl; // write s to the output
    //Reading and writing an unknown number of strings
//    string word;
//    while (cin >> word) //Read until end-of-file
//        cout << word << endl; // write each word followed by a new line
    // getline function
    string line;
    //read input a line at a time until end-of-file
//    while (getline(cin, line))
//        if (!line.empty())
//            //if line has more than 10 characters, print line
//            if (line.size() < 10)
//                cout << line << endl;
    //string::size_type
    auto len = line.size();
    //assignments for string
    string st1(10, 'c'), st2; // st1 is cccccccccc; st2 is an empty string
    st1 = st2; //assignment replace contents of st1 with a copy of st2
               // both st1 and st2 are now empty strings
    // adding two strings
    string add1 = "hello", add2 = "world\n";
    string add3 = add1 + " " + add2; // s3 is hello world\n
    cout << add3 << endl;
    // adding string literals
    //rewriting two strings
    add2 = "world";
    add3 = add1 + ", " + add2 + '\n';
    cout << add3 << endl;
    
    //3.2.3
    // range for
    string str("This is a test.");
    //print the characters in str one character to a line
    for (auto c : str)      // for every char in str
        cout << c << endl;  // print the current character followed by a newline
    
    // use range for and ispunct to count the number of punctuation characters in a string
    string s("Hello World!!!");
    // punct_cnt has the same type that s.size returns
    decltype(s.size()) punct_cnt = 0;
    // count number of punctuation characters in s
    for (auto c : s)    // for every char in s
        if (ispunct(c)) // if the charcter is punctuation
            ++punct_cnt; // increment the punctuation counter
    cout << punct_cnt << " punctuation characters in " << s << endl;
    
    //changing the string to all uppercase using a range for
    string j("Hello");
    for (auto &c : j)
        c = toupper(c);
    cout << j + '\n' << endl;
    
    string ss1("capitalize me");
    if (!ss1.empty())
        ss1[0] = toupper(ss1[0]);
    cout << ss1 << endl;
    
    // process characters in s until run out of characters or hit whitespace
    for (decltype(ss1.size()) index = 0; index != ss1.size() && !isspace(ss1[index]); ++index)
        ss1[index] = toupper(ss1[index]); // capitalize the current character
    cout << ss1 << endl;
    
    //subscripting for random access
//    const string hexdigits = "0123456789ABCDEF"; // possinle hex digits
//    cout << "Enter a series of numbers between 0 and 15" << '\n' << "separated by spaces. hit ENTER when finished: " << endl;
//    string result;          // will hold the resulting hexify'd string
//    string::size_type n;    // hold numbers from the input
//    while (cin >> n)
//        if (n < hexdigits.size()) //ignore invalid input
//            result += hexdigits[n]; // fetch the indicated hex digit
//    cout << "Your hex number is: " << result << endl;
    
    //3.3
    //Vectors
    vector<int> ivec; // ivec holds object of type int
    //vector<Sales_item> Sales_vec; // holds Sales_item
    vector<vector<string>> file; // vectors whose elements are vectors
    
    // 3.3.1
    vector<string> svec; // Default initialization; svec has no type
    vector<int> ivec0; // initially empty
    //give ivec some values
    vector<int> ivec2(ivec); // copy elements of ivec into ivec2
    vector<int> ivec3 = ivec; // copy elements of ivec into ivec3
    // Creating specified number of elements
    vector<int> ivec4(10, -1); // ten int elements, each initialized to -1
    vector<string> svec2(10, "hi!"); // ten strings; each element is "hi!"
    // initalizer vs count
    vector<int> v1 (10); // v1 has ten elements with value 0
    vector<int> v2 {10}; // v2 has one element with value 10
    vector<int> v3 (10, 1); // v3 has ten elements with value 1
    vector<int> v4 {10, 1}; // v4 has two elements with values 10 and 1
    
    // 3.3.2
    //introduction to push_back
//    vector<int> v5; //creation of empty vector
//    for (int i = 0; i != 100; i++)
//        v5.push_back(v5);   //append sequential int 0-99
//    // at end of loop v2 has 100 elements with value 0-99
//    string word;
//    vector<string> text; //empty vector
//    while (cin >> word){
//        text.push_back(text); //append word to text
//    }
//
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto &i : v)       // for each element in v
        i *= i;             // square the element value
    for (auto i : v)        // for each element in v
        cout << i << " ";   // print the element
    cout << endl;
    
    //grades example
    // count the number of grades by cluster of ten: 0-9, 10-19... 90-99, 100
    vector<unsigned> scores(11, 0); // 11 buckets, all initially 0
    unsigned grade;
    while(cin >> grade){            // read the grades
        if (grade <= 100)           // handle only the valid grades
            ++scores[grade/10];     //increment the counter for the cluster
    }
    for (auto &i : scores)
        cout << i << " ";
    cout << endl;
    
    
    //simple stuff
//    int ns = 44;
//    int &ref = ns;
//    int *point = &ref;
//    cout << ref << " " << *point << endl;
//
//    int fr = 20;
//    int z = 10;
//    while (z >= 1){
//        cout << z << endl;
//        --z;
//    }
//    for (int ff = 0; ff < fr; ff = ff + 2 )
//        cout << ff << endl;
        
    
    return 0;
}
