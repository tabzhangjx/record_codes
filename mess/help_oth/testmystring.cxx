/************************************************************************
*  CMPSC 122                                                            *
*  Startup code for HW 3                                                *
*  February 2019                                                        *
*  Hyuntae Na, hzn17@psu.edu                                            *
*                                                                       *
*  Description:                                                         *
*                                                                       *
*  This is a test program for class MyString.                           *
*  Do not modify this file.                                             *
*                                                                       *
*  Please report any bug to hzn17@psu.edu                               *
*************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <cmath>
#include <string>
#include <string.h>
#include "mystring.h"

using namespace std;

template<typename T>
void TestOutput(int& num_tests, int& num_success, T value, T expect, string testname)
{
    num_tests++;
    cout << endl << testname << endl;
    cout << "  result: " << value  << endl;
    cout << "  expect: " << expect << endl;

    if (value == expect)
    {
        num_success++;
        cout << "  test success" << endl;
    }
    else
    {
        cout << "  test failed !!!!!" << endl;
    }
}

int main()
{
    int num_tests = 0;      // total number of tests
    int num_success = 0;    // number of tests succeeded

    try
    {
        // test constructors
        MyString t01;                    TestOutput<string>(num_tests, num_success, (string)t01, ""         , "test 01 - default constructor");
        MyString t02('c');               TestOutput<string>(num_tests, num_success, (string)t02, "c"        , "test 02 - constructor: MyString(const char)");
        MyString t03("abc");             TestOutput<string>(num_tests, num_success, (string)t03, "abc"      , "test 03 - constructor: MyString(const char*)");
        MyString t04(t03);               TestOutput<string>(num_tests, num_success, (string)t04, "abc"      , "test 04 - copy constructor");

        // test getters and setters
                                        TestOutput<int   >(num_tests, num_success,         t04.GetLength()  , 3     , "test 05 - GetLength()");
                                        TestOutput<char  >(num_tests, num_success,         t04.GetCharAt(0) , 'a'   , "test 06 - GetCharAt()");
                                        TestOutput<char  >(num_tests, num_success,         t04.GetCharAt(1) , 'b'   , "test 07 - GetCharAt()");
                                        TestOutput<char  >(num_tests, num_success,         t04[2]           , 'c'   , "test 08 - operator[] (int)");
        t04.SetCharAt(2, 'x');          TestOutput<string>(num_tests, num_success, (string)t04              , "abx" , "test 09 - SetCharAt()");

        // operators
        MyString t05, t06;
        t05 = 's';                      TestOutput<string>(num_tests, num_success, (string)t05, "s"     , "test 10 - operator=(const char)");
        t05 = "qwert";                  TestOutput<string>(num_tests, num_success, (string)t05, "qwert" , "test 11 - operator=(const char*)");
        t06 = t05 = " zxc";             TestOutput<string>(num_tests, num_success, (string)t05, " zxc"  , "test 12 - operator=(const char*)");
                                        TestOutput<string>(num_tests, num_success, (string)t06, " zxc"  , "test 13 - operator=(const MyString&)");

        MyString t07;
        t07 = t03 + '_';                TestOutput<string>(num_tests, num_success, (string)t07, "abc_"      , "test 14 - operator+(const char) const");
        t07 = t03 + "_1234";            TestOutput<string>(num_tests, num_success, (string)t07, "abc_1234"  , "test 15 - operator+(const char*) const");
        t07 = t03 + t05;                TestOutput<string>(num_tests, num_success, (string)t07, "abc zxc"   , "test 16 - operator+(const MyString&) const");

        t07 += '#';                     TestOutput<string>(num_tests, num_success, (string)t07, "abc zxc#"                  , "test 17 - operator+=(const char)");
        t07 += "hjkl";                  TestOutput<string>(num_tests, num_success, (string)t07, "abc zxc#hjkl"              , "test 18 - operator+=(const char*)");
        t07 += t07;                     TestOutput<string>(num_tests, num_success, (string)t07, "abc zxc#hjklabc zxc#hjkl"  , "test 19 - operator+=(const MyString&)");

        MyString t08="siejfin";
        MyString t09="siejfin";
        MyString t10="siejfi_";
        MyString t11="siejfin ";
                                        TestOutput<bool  >(num_tests, num_success, t08 == t09  , true , "test 20 - operator==(const MyString&) const");
                                        TestOutput<bool  >(num_tests, num_success, t08 == t10  , false, "test 21 - operator==(const MyString&) const");
                                        TestOutput<bool  >(num_tests, num_success, t08 == t11  , false, "test 22 - operator==(const MyString&) const");
                                        TestOutput<bool  >(num_tests, num_success, t03 == "abc", true , "test 23 - operator==(const char*) const");
                                        TestOutput<bool  >(num_tests, num_success, t03 == "ab" , false, "test 24 - operator==(const char*) const");

                                        TestOutput<bool  >(num_tests, num_success, t08 != t09  , false, "test 25 - operator!=(const MyString&) const");
                                        TestOutput<bool  >(num_tests, num_success, t08 != t10  , true , "test 26 - operator!=(const MyString&) const");
                                        TestOutput<bool  >(num_tests, num_success, t08 != t11  , true , "test 27 - operator!=(const MyString&) const");
                                        TestOutput<bool  >(num_tests, num_success, t03 != "abc", false, "test 28 - operator!=(const char*) const");

        MyString t12("test-stream");
        {
            // save data of t12 to a file
            ofstream infile;
            infile.open("./testMyString.data");
            infile << t12;
            infile.close();
            // read MyString from the file
            ifstream outfile;
            outfile.open("./testMyString.data");
            MyString tmp;
            outfile >> tmp;
            outfile.close();
            // compare read file with solution
            TestOutput<string>(num_tests, num_success, (string)tmp, "test-stream"   , "test 29 - operator <<, operator >>");
        }
        MyString t13("HelloWorld!");
        {
            // save data of t12 to a file
            ofstream infile;
            infile.open("./testMyString.data");
            infile << t13;
            infile.close();
            // read MyString from the file
            ifstream outfile;
            outfile.open("./testMyString.data");
            MyString tmp;
            outfile >> tmp;
            outfile.close();
            // compare read file with solution
            TestOutput<string>(num_tests, num_success, (string)tmp, "HelloWorld!", "test 30 - operator <<, operator >>");
        }
    }
    catch(const char* message)
    {
        cout << "Exception: " << message << endl << endl;
    }

    // print test results
    int total_tests = 30;
    if(num_success == total_tests)
    {
        cout << endl;
        cout << "Congratulation!" << endl;
        cout << "Your program passed all " << num_success << " test cases." << endl;
    }
    else
    {
        cout << endl;
        cout << "Your program failed " << (total_tests - num_success) << " cases out of " << total_tests << " cases." << endl;
    }
    cout << endl;

    return 0;
}
