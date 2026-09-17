#pragma once

#pragma warning(disable: 4996)
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <cctype>
#include <fstream>
#include <ctime>

using namespace std;


#include <iostream>


class ClsUtil1
{

private :

public:

    //[1]_Print Your Name
    static void printName(string Name)
    {
        cout << "\n-----------------------------";
        cout << "\nYour name is  : " << Name << endl;
        cout << "-----------------------------\n";

    }
    //-------------------------------------------------------------------------
   
	//[2]_Read Name And Print It
    static string ReadName()
    {
        string Name;
        cout << "please enter your Name ?  =>";
        getline(cin, Name);

        return Name;
    }
    //-------------------------------------------------------------------------

    //[3]_Check Odd Or Even
     enum enNumberType { Odd = 1, Even = 2 };

    static int ReadNumber(string Message)
    {
        int Number=0;

        cout << Message << " = > ";
        cin >> Number;
        return Number;
    }
    static float ReadNumber2(string Message)
    {
        float Number = 0;

        cout << Message << " = > ";
        cin >> Number;
        return Number;
    }
    static enNumberType CheckNumberType(int Number)
    {
        int Result = Number % 2;
        if (Result == 0)
        {
            return enNumberType::Even;
        }
        else
        {
            return enNumberType::Odd;

        }

    }
    static void PrintNumberType(enNumberType NumberType, int Number)
    {
        switch (NumberType)
        {


        case enNumberType::Even:
            cout << "\nNumber : [ " << Number << " ] is : Even ." << endl;
            break;

        case  enNumberType::Odd:
            cout << "\nNumber : [ " << Number << " ] is : Odd ." << endl;
            break;

        default:
            cout << "\nno Thing !!!" << endl;
            break;

        }

    }
    //-------------------------------------------------------------------------
    
    //[4]_Hire a driver Case 1
    struct stInfo
    {

        int Age;
        bool HasDrivingLicense;

    };
    static stInfo  ReadInfo()
    {
        stInfo Info;
        cout << "please enter your age ? => ";
        cin >> Info.Age;
       
        cout << "Do you have a driving license? [Yes=1/No=0] => ";
        cin >> Info.HasDrivingLicense;

        return Info;
    }
    static bool IsAccepted(stInfo Info)
    {
        return (Info.Age > 21 && Info.HasDrivingLicense);
    }
    static void PrintResult(stInfo Info)
    {

        if (IsAccepted(Info))
        {
            cout << "\n--------------------------" << endl;
            cout << "\t<< Hired >>" << endl;
            cout << "--------------------------" << endl;
        }
        else
        {
            cout << "\n--------------------------" << endl;
            cout << "\t<< Rejected >>" << endl;
            cout << "--------------------------" << endl;
        }

    }
    //-------------------------------------------------------------------------
   
    //[5]_Hire a driver Case 2
    struct stInfo2
    {

        int Age;
        bool HasDrivingLicense;
        bool HasRecommendation;

    };
    static stInfo2  ReadInfo2()
    {
        stInfo2 Info;
        cout << "please enter your age ? => ";
        cin >> Info.Age;

        cout << "Do you have a driving license? [Yes=1/No=0] => ";
        cin >> Info.HasDrivingLicense;

        cout << "Do you have a Recommendation ? [Yes=1/No=0] => ";
        cin >> Info.HasRecommendation;

        return Info;
    }
    static bool IsAccepted2(stInfo2 Info)
    {
        if (Info.HasRecommendation)
            return true;
        else
            return (Info.Age > 21 && Info.HasDrivingLicense);
    }
    static void PrintResult2(stInfo2 Info)
    {

        if (IsAccepted2(Info))
        {
            cout << "\n--------------------------" << endl;
            cout << "\t<< Hired >>" << endl;
            cout << "--------------------------" << endl;
        }
        else
        {
            cout << "\n--------------------------" << endl;
            cout << "\t<< Rejected >>" << endl;
            cout << "--------------------------" << endl;
        }

    }
    //-------------------------------------------------------------------------

    //[6]_Full Name
    enum enChoice { First_Last = 1, Last_First = 2, Both_options = 3 };
    struct strInfo
    {
        string FirstName;
        string LastName;
    };
    static strInfo ReadFirstAndLastName()
    {
        strInfo Info;
        cout << "please enter your firstrst name ? \n => ";
        cin >> Info.FirstName;
        cout << "please enter your last name ? \n => ";
        cin >> Info.LastName;

        return Info;
    }
    static string GetFullName(strInfo Info,bool Reversed)
    {
        string FullName = " ";
        if(Reversed)
            FullName = Info.LastName + " " + Info.FirstName;
        else
            FullName = Info.FirstName + " " + Info.LastName;
        return FullName;
    }
    /*static string GetReciveFullName(strInfo Info)
    {
        string FullName = " ";
        FullName = Info.LastName+" "+ Info.FirstName;
        return FullName;
    }*/
    static void PrintFullNameFirstNameAndLastName(string FullName, strInfo Info)
    {
        cout << "\n------------------------------------\n";
        cout << "First Name is : " << Info.FirstName << endl;
        cout << "Last Name is  : " << Info.LastName << endl;
        cout << "FullName is   : " << FullName << endl;
        cout << "FullName is   : " << GetFullName(Info, false) << endl;
        cout << "FullName is   : " << Info.FirstName + " " + Info.LastName << endl;
        cout << "------------------------------------\n";
    }
    static void PrintReversedFullName(string FullName, strInfo Info)
    {
        cout << "\n------------------------------------\n";
        cout << "First Name is : " << Info.FirstName << endl;
        cout << "Last Name is  : " << Info.LastName << endl;
        cout << "FullName is   : " << FullName << endl;
        cout << "FullName is   : " << GetFullName(Info, true) << endl;
        cout << "FullName is   : " << Info.LastName + " " + Info.FirstName<<endl;
        cout << "------------------------------------\n";
    }
    static void RunFunction(enChoice Choice, strInfo Info)
    {
        switch (Choice)
        {

        case enChoice::First_Last:
            system("cls");
            PrintFullNameFirstNameAndLastName(GetFullName(Info, false), Info);
            GoBackToMenue(Info);
            break;
        case enChoice::Last_First:
            system("cls");
            PrintReversedFullName(GetFullName(Info, true), Info);
            GoBackToMenue(Info);
            break;
        case enChoice::Both_options: 
            system("cls");
            PrintFullNameFirstNameAndLastName(GetFullName(Info, false), Info);
            PrintReversedFullName(GetFullName(Info, true), Info);
            GoBackToMenue(Info);
            break;
        default:
            system("cls");
            cout << "Good Luck !!!\n"; 
            break;
        }

    }
    static void ShowOption(strInfo Info)
    {
        int Number = 0;
        system("cls");
        cout << "How would you like your name to be displayed?\n";
        cout << "1: FirstName and LastName ." << endl;
        cout << "2: LastName and FirstName ." << endl;
        cout << "3: Both options ." << endl;
        cout << "4: Exit ." << endl;
        cout << "------------------------------------------\n";
        cin >> Number;
        RunFunction((enChoice)Number, Info);
    }
    static void GoBackToMenue(strInfo Info)
    {
       
        cout << "Please enter any key to back to Menue....";
        system("pause>0");
        ShowOption(Info);

    }
    //-------------------------------------------------------------------------
    
    //[7]_Half Number
    static float CalculateHalfNumber(int Number)
    {
        return (float)Number / 2;
    }
    static void PrintResultOfHalfNumber(int Number)
    {
        cout << "---------------------------------------------\n";
        string Result = "Result [ Half of Number ] : " + to_string(Number) + "/2 = " + to_string(CalculateHalfNumber(Number));
        cout << Result << endl;
        printf("\nResult = [ Half of %d ]     : %d/2 = %.1f ", Number, Number, CalculateHalfNumber(Number));
        printf("\nResult = [ Half of %0*d ]     : %0*d/2 = %.1f ", 2,Number,2, Number, CalculateHalfNumber(Number));
        printf("\nResult = [ Half of %0d ]   : %0d/2 = %.*f ", Number, Number, 3,CalculateHalfNumber(Number));
        printf("\n%s = [ Half of %0d ]   : %0d/2 = %.*f ","Result", Number, Number, 3, CalculateHalfNumber(Number));
        printf("\n%*s = [ Half of %0d ]   : %0d/2 = %.*f ", 3,"Result", Number, Number, 3, CalculateHalfNumber(Number));
        cout << "\n---------------------------------------------\n";

    }
    //-------------------------------------------------------------------------
    
    //[8]_Mark Pass Fail
    enum enPassFail{ Pass = 1 ,Fail = 2 };
    static int ReadMark()
    {

        int Mark;
        cout << "Please enter your Mark ?\n =>";
        cin >> Mark;
        return Mark;

    }
    static enPassFail CheckMark(int Mark)
    {

        if (Mark >= 50)
        {
            return enPassFail::Pass;

        }

        else
        {
            return enPassFail::Fail;

        }
    }
    static void PrintResultOfMark(int Mark)
    {

        if (CheckMark(Mark) == enPassFail::Pass)
        {
            cout << "---------------------------------------------\n";
            cout << "\tYou are successful ." << endl;
            cout << "---------------------------------------------\n";
        }
        else if (CheckMark(Mark) == enPassFail::Fail)
        {
            cout << "---------------------------------------------\n";
            cout << "\tYou failed ." << endl;
            cout << "---------------------------------------------\n";
        }
    }
    //-------------------------------------------------------------------------
    
    //[9]_Sum Of 3 Numbers
    struct str3Number
    {

        int Number1, Number2, Number3,TheSum;

    };
    static str3Number ReadNumbers()
    {

        str3Number Info;
        cout << "please enter number 1 ?\n => ";
        cin >> Info.Number1;
        cout << "please enter number 2 ?\n => ";
        cin >> Info.Number2;
        cout << "please enter number 3 ?\n => ";
        cin >> Info.Number3;

        return Info;
    }
    static int SumOf3Numbers(str3Number& Info)
    {

        Info.TheSum = Info.Number1+ Info.Number2 + Info.Number3;
        return   Info.TheSum;

    }
    static void PrintResultSumOf3Numbers(str3Number Info)
    {
        cout << "\n-----------------------------------\n";
        cout << "  The Sum = " << Info.Number1 << " + " << Info.Number2 << " + " << Info.Number3 << " = " << SumOf3Numbers(Info) << endl;
        cout << "-----------------------------------\n";
    }
    //-------------------------------------------------------------------------
    static void ReadNumbers2(int& Number1, int& Number2, int& Number3)
    {
        cout << "please enter number 1 ?\n => ";
        cin >> Number1;
        cout << "please enter number 2 ?\n => ";
        cin >> Number2;
        cout << "please enter number 3 ?\n => ";
        cin >> Number3;
    }
    static int SumOf3Numbers2(int Number1, int Number2, int Number3)
    {
        return   Number1 + Number2 + Number3;
    }
    static void PrintResultSumOf3Numbers2(int Number1, int Number2, int Number3)
    {
        cout << "\n---------------------------------\n";
        cout << "  The Sum = " << Number1 << " + " << Number2 << " + " << Number3 << " = " << SumOf3Numbers2(Number1, Number2, Number3) << endl;
        cout << "---------------------------------\n";
    }
    //-------------------------------------------------------------------------
    static void  ReadNumbers3(int  Array[3])
    {

        for (int i = 0;i < 3;i++)
        {
            printf("please enter number %d ?\n => ",i+1);
            cin >> Array[i];
        }
    }
    static int SumOf3Numbers3(int  Array[3])
    {
        int Sum = 0;
        for (int i = 0;i < 3;i++)
        {
              Sum += Array[i];
        }
        return  Sum;

    }
    static void PrintResultSumOf3Numbers3(int  Array[3])
    {
        cout << "---------------------------------\n";
        cout << "  The Sum = ";
            for (int i = 0;i < 3;i++)
            {
                
                cout << to_string(Array[i]);
                if (i == 2)
                    break;
                cout<<" + ";

            }
        cout << " = " << SumOf3Numbers3(Array) << endl;
        cout << "---------------------------------\n";
    }
    //-------------------------------------------------------------------------
    
    //[10]_Average Of 3 Marks
    static float CalculateAverage(str3Number Info)
    {

        return (float)SumOf3Numbers(Info) / 3;
    }
    static void PrintResultAverageOf3Marks(str3Number Info)
    {
        cout << "\n--------------------------------------------------\n";
        cout << "  The Average = " << Info.Number1 << " + " << Info.Number2 << " + " << Info.Number3 << " = "
             << SumOf3Numbers(Info)<<" / 3 = "<< CalculateAverage(Info) << endl;
        cout << "--------------------------------------------------\n";
    }
    //-------------------------------------------------------------------------
    static float CalculateAverage2(int& Number1, int& Number2, int& Number3)
    {

        return (float)SumOf3Numbers2(Number1, Number2, Number3) / 3;
    }
    static void PrintResultAverageOf3Marks2(int Number1, int Number2, int Number3)
    {
        cout << "\n--------------------------------------------------\n";
        cout << "  The Average = " << Number1 << " + " << Number2 << " + " << Number3 << " = "
            << SumOf3Numbers2(Number1, Number2, Number3) << " / 3 = " << CalculateAverage2(Number1, Number2, Number3) << endl;
        cout << "--------------------------------------------------\n";
    }
    //-------------------------------------------------------------------------
    static float CalculateAverage3(int  Array[3])
    {

        return (float)SumOf3Numbers3(Array) / 3;
    }
    static void PrintResultAverageOf3Marks3(int  Array[3])
    {
        cout << "\n--------------------------------------------------\n";
        cout << "  The Average = ";
            for (int i = 0;i < 3;i++)
            {

                cout << to_string(Array[i]);
                if (i == 2)
                    break;
                cout << " + ";

            }
            cout << " = " << SumOf3Numbers3(Array) << " / 3 = " << CalculateAverage3(Array) << endl;
        cout << "--------------------------------------------------\n";
    }
    //-------------------------------------------------------------------------
   
    //[11]_Avrage Pass/Fail
    static enPassFail CheckAverage(float Average)
    {

        if (Average >= 50)
        {
            return enPassFail::Pass;

        }

        else
        {
            return enPassFail::Fail;

        }

    }
    static void PrintResultPaasOrFail(float Average)
    {
        cout << "\n----------------------------\n";
        cout << "\n Your Average is : " << Average << endl;

        if (CheckAverage(Average) == enPassFail::Pass)
            cout << "\n You Passed" << endl;
        else
            cout << "\n You Faild\n";

        cout << "\n----------------------------\n";

    }
    //-------------------------------------------------------------------------

    //[12]_Max Of Two Numbers
    struct stTwoNumbers
    {

        int Number1, Number2,Number3;

    };
    static stTwoNumbers Read2Numbers()
    {
        stTwoNumbers Info;
        cout << "please enter Number1 ?\n => ";
        cin >> Info.Number1;
        cout << "please enter Number2 ?\n => ";
        cin >> Info.Number2;
        return Info;
    }
    static int Maxof2Numbers(stTwoNumbers Info)
    {
        if (Info.Number1 > Info.Number2)
            return Info.Number1;
        else
            return Info.Number2;
    }
    static void PrintMaximumOf2Numbers(stTwoNumbers Info)
    {
        cout << "-----------------------------------------\n";
        cout << "The Maximum Number of [ " << Info.Number1 << " , " << Info.Number2 << " ] " << " is : " << Maxof2Numbers(Info) << endl;
        cout << "-----------------------------------------\n";
    }
    //-------------------------------------------------------------------------
    static void Read2Numbers2(int& Number1, int& Number2)
    {
        cout << "please enter Number1 ?\n => ";
        cin >> Number1;
        cout << "please enter Number2 ?\n => ";
        cin >> Number2;
    }
    static int Maxof2Numbers2(int Number1, int Number2)
    {

        if (Number1 > Number2)
            return Number1;
        else
            return Number2;
    }
    static void PrintMaximumOf2Numbers2( int Number1, int Number2)
    {
        cout << "\n--------------------------------------------\n";
        cout << "The Maximum Number of [ " << Number1 << " , " << Number2 << " ] " << " is : " << Maxof2Numbers2(Number1, Number2) << endl;
        cout << "--------------------------------------------\n";
    }
    //-------------------------------------------------------------------------
    static void Read2Numbers3(int Array[2])
    {
        for (int i = 0;i < 2;i++)
        {
            printf("please enter number %d ?\n => ", i + 1);
            cin >> Array[i];
        }
    }
    static int Maxof2Numbers3(int Array[2])
    {
        if (Array[0] == Array[1])
            return 0;
        for (int i = 0;i < 2;i++)
        {

            if (Array[i] > Array[i+1])
                return Array[i];
            else
                return Array[i + 1];
        }
    }
    static void PrintMaximumOf2Numbers3(int Array[2])
    {
        cout << "\n--------------------------------------------\n";
        cout << "The Maximum Number of [ ";
        for (int i = 0;i < 2;i++)
        {
           cout<< Array[i];
           if (i == 1)
               break;

           cout << " , ";
        }
        cout<<" ] " << " is : " << Maxof2Numbers3(Array) << endl;
        cout << "--------------------------------------------\n";
    }
    //-------------------------------------------------------------------------
   
    //[13]_Max Of Three Numbers
    static stTwoNumbers Read3Numbers()
    {
        stTwoNumbers Info;
        cout << "please enter Number1 ?\n => ";
        cin >> Info.Number1;
        cout << "please enter Number2 ?\n => ";
        cin >> Info.Number2;
        cout << "please enter Number3 ?\n => ";
        cin >> Info.Number3;
        return Info;
    }
    static int Maxof3Numbers(stTwoNumbers Info)
    {
        // 1 2 3
        if (Info.Number1 == Info.Number2 == Info.Number3)
            return 0;
        if (Info.Number1 > Info.Number2)
            if (Info.Number1 > Info.Number3)
                return Info.Number1;
            else
                return Info.Number3;

        else
            if (Info.Number2 > Info.Number3)
                return Info.Number2;
            else
                return Info.Number3;

    }
    static void PrintMaximumOf3Numbers(stTwoNumbers Info)
    {
        cout << "--------------------------------------------\n";
        cout << "The Maximum Number of [ " << Info.Number1 << " , " << Info.Number2 << " , " << Info.Number3 << " ] " << " is : " << Maxof3Numbers(Info) << endl;
        cout << "--------------------------------------------\n";
    }
    //-------------------------------------------------------------------------
    static void Read3Numbers2(int& Number1, int& Number2 , int& Number3)
    {
        cout << "please enter Number1 ?\n => ";
        cin >> Number1;
        cout << "please enter Number2 ?\n => ";
        cin >> Number2;
        cout << "please enter Number3 ?\n => ";
        cin >> Number3;
    }
    static int Maxof3Numbers2(int Number1, int Number2, int Number3)
    {
        // 1 2 3
        if (Number1 == Number2 == Number3)
            return 0;
        if (Number1 > Number2)
            if (Number1 > Number3)
                return Number1;
            else
                return Number3;

        else
            if (Number2 > Number3)
                return Number2;
            else
                return Number3;

    }
    static void PrintMaximumOf3Numbers2(int Number1, int Number2, int Number3)
    {
        cout << "--------------------------------------------\n";
        cout << "The Maximum Number of [ " << Number1 << " , " << Number2 << " , " << Number3 << " ] " << " is : " << Maxof3Numbers2(Number1, Number2, Number3) << endl;
        cout << "--------------------------------------------\n";
    }
    //-------------------------------------------------------------------------
    static void Read3Numbers3(int Array[3])
    {
        for (int i = 0;i < 3;i++)
        {
            printf("please enter number %d ?\n => ", i + 1);
            cin >> Array[i];
        }
    }
    static int Maxof3Numbers3(int Array[3])
    {
        // 1 2 3

        if (Array[0] == Array[1] == Array[2])
            return 0;
        if (Array[0] > Array[1])
            if (Array[0] > Array[2])
                return Array[0];
            else
                return Array[2];

        else
            if (Array[1] > Array[2])
                return Array[1];
            else
                return Array[2];

    }
    static void PrintMaximumOf3Numbers3(int Array[3])
    {
        cout << "\n--------------------------------------------\n";
        cout << "The Maximum Number of [ ";
        for (int i = 0;i < 3;i++)
        {
            cout << Array[i];
            if (i == 2)
                break;

            cout << " , ";
        }
        cout << " ] " << " is : " << Maxof3Numbers3(Array) << endl;
        cout << "--------------------------------------------\n";
    }
    //-------------------------------------------------------------------------

    //[14]_Swap Two Numbers
    static void TheNumberBefoureSwap(stTwoNumbers Info)
    {
        cout << "\nBefore Swap" << endl;
        cout << "-----------------------------------\n";
        cout << "Number1 = " << Info.Number1 << endl;
        cout << "Number2 = " << Info.Number2 << endl;
        cout << "-----------------------------------\n";
    }
    static void SwaP(stTwoNumbers &Info)
    {
        int Temp;
        Temp = Info.Number1;
        Info.Number1 = Info.Number2;
        Info.Number2 = Temp;

    }
    static void TheNumberAfterSwap(stTwoNumbers Info)
    {
        cout << "\nAfter Swap" << endl;
        cout << "-----------------------------------\n";
        cout << "Number1 = " << Info.Number1 << endl;
        cout << "Number2 = " << Info.Number2 << endl;
        cout << "-----------------------------------\n";
    }
    //-------------------------------------------------------------------------
    static void TheNumberBefoureSwap2(int Number1, int Number2)
    {
        cout << "\nBefore Swap" << endl;
        cout << "-----------------------------------\n";
        cout << "Number1 = " << Number1 << endl;
        cout << "Number2 = " << Number2 << endl;
        cout << "-----------------------------------\n";
    }
    static void SwaP2(int& A, int& B)
    {
        int Temp;
        Temp = A;
        A = B;
        B = Temp;

    }
    static void TheNumberAfterSwap2(int Number1, int Number2)
    {
        cout << "\nAfter Swap" << endl;
        cout << "-----------------------------------\n";
        cout << "Number1 = " << Number1 << endl;
        cout << "Number2 = " << Number2 << endl;
        cout << "-----------------------------------\n";


    }
    //-------------------------------------------------------------------------
    static void TheNumberBefoureSwap3(int Array[2])
    {
        cout << "\nBefore Swap" << endl;
        cout << "-----------------------------------\n";
        cout << "Number1 = " << Array[0] << endl;
        cout << "Number2 = " << Array[1] << endl;
        cout << "-----------------------------------\n";
    }
    static void SwaP3(int Array[2])
    {
        int Temp;
        Temp = Array[0];
        Array[0] = Array[1];
        Array[1] = Temp;

    }
    static void TheNumberAfterSwap3(int Array[2])
    {
        cout << "\nAfter Swap" << endl;
        cout << "-----------------------------------\n";
        cout << "Number1 = " << Array[0] << endl;
        cout << "Number2 = " << Array[1] << endl;
        cout << "-----------------------------------\n";
    }
    //-------------------------------------------------------------------------

    //[15]_Rectangle Area
    static void ReadRectangleArea(int& Width, int& Length)
    {
        cout << "Please enter rectangle width ?\n =>";
        cin >> Width;
        cout << "Please enter rectangle length ?\n =>";
        cin >> Length;
    }
    static float CalculateRectangleArea(int Width, int Length)
    {   
        return Width * Length;
    }
    static void PrintRectangleArea(float Area)
    {
        cout << "\n------------------------------------------\n";
        cout << "Rectangle Area = " << Area << endl;
        cout << "------------------------------------------\n";
    }
    //-------------------------------------------------------------------------

    //[16]_Rectangle Area By Diagonal & Side
    static void ReadRectangleAreaBySideAndDiagonal(int& side, int& diagonal)
    {
        cout << "Enter rectangle Side A ?\n =>";
        cin >> side;
        cout << "Enter rectangle diagonal D ?\n =>";
        cin >> diagonal;
    }
    static float RectangleAreaBySideAndDiagonale(int& side, int& diagonal)
    {
        float Area=0;
        Area = side * sqrt(pow(diagonal, 2) - pow(side, 2));
        return float(Area);
    }
    //-------------------------------------------------------------------------
    
    //[17]_Triangle Area
    static void ReadTriangleArea(float& base, float& Height)
    {
        cout << "Enter triangle Base A ?\n =>";
        cin >> base;
        cout << "Enter triangle Height H ?\n =>";
        cin >> Height;
    }
    static float TriangleArea(float& base, float& Height)
    {
        float Area;
        Area = (base / 2) * Height;
        return Area;
    }
    static void PrintTriangleArea(float Area)
    {
        cout << "\n------------------------------------------\n";
        cout << "Triangle Area = " << Area << endl;
        cout << "------------------------------------------\n";
    }
    //-------------------------------------------------------------------------

    //[18]_Circle Area
    static float ReadRadious()
    {
        float Radious =0;
        cout << "Enter the radiuos R ?\n =>";
        cin >> Radious;
        return Radious;
    }
    static float CircleArea(float Radious)
    {
        float Area;
        const float PI = 3.141592653589793238;
        Area = PI * pow(Radious, 2);
        return Area;
    }
    static void PrintCircleArea(float Area)
    {
        cout << "\n------------------------------------------\n";
        cout << "Circle Area = " << Area << endl;
        cout << "------------------------------------------\n";
    }
    //-------------------------------------------------------------------------

    //[19]_Circle Area By Diameter
    static float ReadDiameter()
    {
        float Diameter;
        cout << "Enter radious D ?\n =>";
        cin >> Diameter;
        return Diameter;
    }
    static float CircleAreaByDiameter(float Diameter)
    {
        float Area;
        const float PI = 3.141592653589793238;
        Area = (PI * pow(Diameter, 2)) / 4;
        return Area ;
    }
    //-------------------------------------------------------------------------

    //[20]_Circle Area Inscribed in a Square
    static float ReadSquareside()
    {
        float A;
        cout << "Enter Square Side A ?\n =>";
        cin >> A;
        return A;
    }
    static float CircleAreaInscribedInSquare(float A)
    {
        float Area=0;
        const float PI = 3.141592653589793238;
        Area = (PI * pow(A, 2)) / 4;
        return Area;
    }
    //-------------------------------------------------------------------------

    //[21]_Circle Area Along The Circumference
    static float ReadCircumference()
    {
        float L;
        cout << "Please Enter  Circumference  ?\n =>";
        cin >> L;
        return L;
    }
    static float CircleAreaByCircumference(float L)
    {
        float Area;
        const float PI = 3.141592653589793238;
        Area = pow(L, 2) / (4 * PI);
        return Area;
    }
    //-------------------------------------------------------------------------

    //[22]_Circle Area Inscribed in an Isosceles Triangle
    static void ReadTraingleData(float& A, float& B)
    {


        cout << "Enter Triangle side A ?\n =>";
        cin >> A;
        cout << "Enter Triangle base B ?\n =>";
        cin >> B;


    }
    static float CircleAreaByTraingle(float A, float B)
    {
        float Area;
        const float PI = 3.141592653589793238;
        Area = PI * (pow(B, 2) / 4) * ((2 * A - B) / (2 * A + B));
        return Area;
    }
    //-------------------------------------------------------------------------

    //[23]_Circle Area Described Around an Arbitrary Triangle
    static void ReadTraingleData2(float& A, float& B, float& C)
    {
        cout << "Enter Triangle side A ?\n =>";
        cin >> A;
        cout << "Enter Triangle base B ?\n =>";
        cin >> B;
        cout << "Enter Triangle side C ?\n =>";
        cin >> C;
    }
    static float CircleAreaByATraingle(float A, float B, float C)
    {
        float Area;
        const float Pi = 3.141592653589793238;
        float P = (A + B + C) / 2;
        float T;
        T = (A * B * C) / (4 * sqrt(P * (P - A) * (P - B) * (P - C)));
        Area = Pi * pow(T, 2);
        return Area;
    }
    //-------------------------------------------------------------------------

    //[24]_Validate Number In Range
    static bool ValidateNumberInRange(int& Number, int From, int To)
    {

        return (Number >=From && Number<=To);
    }
    static int ReadAge(int From,int To)
    {
        int Age;
        cout << "please enter the age between [ "<<From<<" : "<<To<<" ] ? = >";
        cin >> Age;
        return Age;
    }
    static void PrintAge(int Age,int From, int To)
    {
        if (ValidateNumberInRange(Age, From, To))
        {
            cout << "\n------------------------------------------\n";
            cout << "   Your Age is : [ " << Age << " ] " << endl;
            cout << "------------------------------------------\n";
        }
        else
        {
            cout << "\n------------------------------------------\n";
            cout << "     Is Invalid Age " << endl;
            cout << "------------------------------------------\n";
        }
       
    }
    //-------------------------------------------------------------------------

    //[25]_Read Until Age Between 18 and 45
    static int ReadUntilAgeBetween(int From, int To)
    {
        int Age = 0;
        do
        {
            Age = ReadAge(From, To);

        } while (!ValidateNumberInRange(Age, From, To));

        return Age;
    }
    static void PrintResultAge(int Age, int From, int To)
    {
        cout << "\n------------------------------------------\n";
        cout << "   Your Age is : [ " << Age << " ] " << endl;
        cout << "------------------------------------------\n";
    }

    //[11]_












};

