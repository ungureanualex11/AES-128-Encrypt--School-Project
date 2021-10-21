#include <iostream>
using namespace std;
#include <string>
#include <math.h>
//#include <algorithm>
#include <fstream>
#include <sstream>

void stringToArray(string s, int array[8]) {
    for (int i = 0; i < 8; i++)
        array[i] = s[i]-48;

}
string arrayToString(int array[8]) {
    string s = "";
    for (int i = 0; i < 8; i++)
        s += array[i]+48;
    return s;
}
string HexToBin(string hexdec)
{
    string s = "";
    long int i = 0;

    while (hexdec[i]) {

        switch (hexdec[i]) {
        case '0':
            s = s + "0000";
            break;
        case '1':
            s = s + "0001";
            break;
        case '2':
            s = s + "0010";
            break;
        case '3':
            s = s + "0011";
            break;
        case '4':
            s = s + "0100";
            break;
        case '5':
            s = s + "0101";
            break;
        case '6':
            s = s + "0110";
            break;
        case '7':
            s = s + "0111";
            break;
        case '8':
            s = s + "1000";
            break;
        case '9':
            s = s + "1001";
            break;
        case 'A':
        case 'a':
            s = s + "1010";
            break;
        case 'B':
        case 'b':
            s = s + "1011";
            break;
        case 'C':
        case 'c':
            s = s + "1100";
            break;
        case 'D':
        case 'd':
            s = s + "1101";
            break;
        case 'E':
        case 'e':
            s = s + "1110";
            break;
        case 'F':
        case 'f':
            s = s + "1111";
            break;
        }
        i++;
    }
    return s;
}
void create_sBox(string a[16][16]) {

    fstream file;
   	string word, filename;   
    filename = "sbox.txt";
    file.open(filename.c_str());
    int i=0, j = 0;
    while (file >> word)
    	{
        
        a[i][j] = HexToBin(word);
        if (j < 15)
            j++;
        else 
            if (i < 15)
            {
                i++;
                j = 0;
            }             
    	}

    
    
   
}
string string_to_hex(const std::string& input)
{
    static const char hex_digits[] = "0123456789ABCDEF";

    std::string output;
    output.reserve(input.length() * 2);
    for (unsigned char c : input)
    {
        output.push_back(hex_digits[c >> 4]);
        output.push_back(hex_digits[c & 15]);
    }
    return output;
}
string add_front_zeros(string s) {
    while (s.length() < 8)
        s = "0" + s;
    return s;
}
void PrintArray(int c[],int n) {
    for (int i = 0; i < n; i++)
        cout << c[i]<<" ";
}
int HexCharToInt(char c) {
    if (c == '0')
        return 0;
    if (c == '1')
        return 1;
    if (c == '2')
        return 2;
    if (c == '3')
        return 3; 
    if (c == '4')
        return 4;
    if (c == '5')
        return 5;
    if (c == '6')
        return 6;
    if (c == '7')
        return 7;
    if (c == '8')
        return 8;
    if (c == '9')
        return 9;
    if (c == 'a')
        return 10;
    if (c == 'b')
        return 11;
    if (c == 'c')
        return 12;
    if (c == 'd')
        return 13;
    if (c == 'e')
        return 14;
    if (c == 'f')
        return 15;
}
string fourBinaryToHex(string s) {
    if (s == "0000")
        s = "0";
    if (s == "0001")
        s = "1";
    if (s == "0010")
        s = "2";
    if (s == "0011")
        s = "3";
    if (s == "0100")
        s = "4";
    if (s == "0101")
        s = "5";
    if (s == "0110")
        s = "6";
    if (s == "0111")
        s = "7";
    if (s == "1000")
        s = "8";

    if (s == "1001")
        s = "9";
    if (s == "1010")
        s = "a";
    if (s == "1011")
        s = "b";
    if (s == "1100")
        s = "c";
    if (s == "1101")
        s = "d";
    if (s == "1110")
        s = "e";
    if (s == "1111")
        s = "f";

    return s;
}
void PrintBiArray(string M[4][4]) {
    string temp,half1,half2;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            {
            temp = M[i][j];
            half1 = temp[0];
            half1 += temp[1];
            half1 += temp[2];
            half1 += temp[3];
          
            half2 = temp[4];
            half2 += temp[5];
            half2 += temp[6];
            half2 += temp[7];

            
            half1 = fourBinaryToHex(half1);
            half2 = fourBinaryToHex(half2);

            cout << half1 << half2 << "  ";
             }
        cout << endl<<endl;
    }
    cout << endl;
}
void putInBiArray(string s,string BiArray[4][4]) {
    stringstream iss(s);
    string word;
    int i = 0, j = 0;
    while (iss >> word)
    {  
        if (i < 4)
        {
            BiArray[i][j] = word;
            i++;
        }
        
        if (i == 4)
        {
            j++;
            i = 0;
        }
    }
}
void hexBiArray_to_binaryBiArray(string M[4][4])
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            M[i][j] = HexToBin(M[i][j]);
}

void Addition(int a[],int b[],int c[],int n) {
    
    for (int i = 0; i < n; i++)
        c[i] = a[i] ^ b[i];
    
   }
void Multiplication(int a[8], int b[8], int c[8]) {
    ///////////////////etapa de inmultire, cu adunarea ="xor"/////////////////
    int temp_res[15];
    for (int i = 0; i < 15; i++)
        temp_res[i] = 0;

    int m[8][15];
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 15; j++)
            m[i][j] = 0;

    for(int i=7;i>=0;i--)
        if (b[i] == 1)
        {
            for (int j = i; j <= i + 7; j++)
                m[7 - i][j] = a[j-i];
        }



    for (int j = 0; j <15; j++)
    {
        for (int i = 0; i < 8; i++)
            temp_res[j] = temp_res[j]^m[i][j];
    }

  //  cout << "Rezultate dupa prima etapa= " << endl;
  //   PrintArray(temp_res, 15);

/*__________________________________________________________________________________*/

    //////////////////////Etapa 2 de modulo /////////////////////////////
    string s1 = "";
    for (int i = 0; i < 15; i++)
        s1 += to_string(temp_res[i]);
    
    string s2 = "100011011";
    while ((int)s1.length() - (int)s2.length() >= 0)
    {
        /*cout <<"s2 " << s2<<endl;
        cout <<"s1-s2 "<<s1.length() - s2.length() << endl;*/
        //incepe impartirea
        string temp = s2;
        //numar zerouri pt  a ajunge la gradul lui s1
        for (int i = 0; i < s1.length() - s2.length(); i++)
            temp += "0";

        //salvam in s1 xor dintre s1 si temp
        for (int i = 0; i < s1.length(); i++)
        {
            int s1_int = s1[i] - 48;
            int temp_int = temp[i] - 48;
            s1[i] = (char)(s1_int ^ temp_int + 48);
        }

        //eliminam toate zerourile din fata  scazand astfel gradul polinomului
        while (s1[0] == '0')
        {
            for (int i = 0; i < s1.length() - 1; i++)
                s1[i] = s1[i + 1];
            if (!s1.empty()) {
                s1.pop_back();
            }
        }
        //cout << "\ns1 " << s1 << endl;
    } 
    
    s1=add_front_zeros(s1);
    //s1 to c
    for (int i = 0; i < 8; i++)
        c[i] = s1[i]-48;
  
}
void SubBytes(string M[4][4], string sbox[16][16]) {
    string lin;
    string col;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            string str = M[i][j];
            lin = "";
            col = "";
             lin = str[0];
             lin += str[1];
             lin += str[2];
             lin += str[3];

             col = str[4];
             col += str[5];
             col += str[6];
             col += str[7];

             lin = fourBinaryToHex(lin);
             col = fourBinaryToHex(col);
 
             int lin_int = HexCharToInt(lin[0]);
             int col_int = HexCharToInt(col[0]);
           //  cout << M[i][j] <<" = "<< lin_int <<" + "<< col_int << endl;
             M[i][j] = sbox[lin_int][col_int];

        }

}
void ShiftRows(string M[4][4]) {
    
    string aux;

    //linia nr 1 , o pozitie shiftata stanga
    aux = M[1][0];
    M[1][0] = M[1][1];
    M[1][1] = M[1][2];
    M[1][2] = M[1][3];
    M[1][3] = aux;

    //linia nr 2, doua pozitii shiftate stanga
    aux = M[2][0];
    M[2][0] = M[2][2];
    M[2][2] = aux;
    aux = M[2][1];
    M[2][1] = M[2][3];
    M[2][3] = aux;

    //linia nr 3, trei pozitii shiftate stanga
    aux = M[3][3];
    M[3][3] = M[3][2];
    M[3][2] = M[3][1];
    M[3][1] = M[3][0];
    M[3][0] = aux;




    
}
void MixColumns(string M[4][4])
{
    int h01[8] = { 0,0,0,0,0,0,0,1 };
    int h02[8] = { 0,0,0,0,0,0,1,0 };
    int h03[8] = { 0,0,0,0,0,0,1,1 };
    string M_prim[4][4];
    int t1[8], t2[8], t3[8], t4[8];
    int line0[8], line1[8], line2[8], line3[8];
    int a[8], b[8], c[8];
    for (int j = 0; j < 4; j++)
    {
        stringToArray(M[0][j], line0); //s 0,c din document FIPS
        stringToArray(M[1][j], line1); 
        stringToArray(M[2][j], line2);
        stringToArray(M[3][j], line3);

       
        //calcul primul element de pe coloana j din M_prim
        Multiplication(h02, line0, t1);
        Multiplication(h03, line1, t2);
        Multiplication(h01, line2, t3);
        Multiplication(h01, line3, t4);
        Addition(t1, t2, a, 8);
        Addition(t3, t4, b, 8);
        Addition(a, b, c, 8);   
        //in c se gaseste sub forma de array primul element de pe coloana j din M_prim
        M_prim[0][j] = arrayToString(c);
        /*for (int i = 0; i < 8; i++)
            t1[i] = '0';*/
        //calcul al doilea element de pe coloana j din M_prim
        Multiplication(h01, line0, t1);
        Multiplication(h02, line1, t2);
        Multiplication(h03, line2, t3);
        Multiplication(h01, line3, t4);
        Addition(t1, t2, a, 8);
        Addition(t3, t4, b, 8);
        Addition(a, b, c, 8);
        M_prim[1][j] = arrayToString(c);
      

        //calcul al treilea element de pe coloana j din M_prim
        Multiplication(h01, line0, t1);
        Multiplication(h01, line1, t2);
        Multiplication(h02, line2, t3);
        Multiplication(h03, line3, t4);
        Addition(t1, t2, a, 8);
        Addition(t3, t4, b, 8);
        Addition(a, b, c, 8);
        M_prim[2][j] = arrayToString(c);

        //calcul al patrulea element de pe coloana j din M_prim
        Multiplication(h03, line0, t1);
        Multiplication(h01, line1, t2);
        Multiplication(h01, line2, t3);
        Multiplication(h02, line3, t4);
        Addition(t1, t2, a, 8);
        Addition(t3, t4, b, 8);
        Addition(a, b, c, 8);
        M_prim[3][j] = arrayToString(c);

      
    }
    //la iesirea din acest for in M_prim se gasesc toate elementele necesare
    //se trec acestea din M_prim in M 
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            M[i][j] = M_prim[i][j];

}
void AddRoundKey(string M[4][4], string Key[4][4]) {
    
    int array_M[8], array_Key[8], array_res[8];
    for(int i=0;i<4;i++)
        for (int j = 0; j < 4; j++)
        {
            stringToArray(M[i][j], array_M);
            stringToArray(Key[i][j], array_Key);
            Addition(array_M, array_Key, array_res,8);
            M[i][j] = arrayToString(array_res);

        }
}

string xorBetweenStrings(string s1, string s2) {
    int int_s1[8], int_s2[8], res[8];
    stringToArray(s1, int_s1);
    stringToArray(s2, int_s2);
    Addition(int_s1, int_s2, res, 8);

    return arrayToString(res);
}
void KeyExpansion(string Key[4][4], string sbox[16][16], int round_number) {

    string newKey[4][4];
    string v[4], Rcon[4] = { "00","00","00","00" };
    if (round_number == 1)
        Rcon[0] = "01";
    if (round_number == 2)
        Rcon[0] = "02";
    if (round_number == 3)
        Rcon[0] = "04";
    if (round_number == 4)
        Rcon[0] = "08";
    if (round_number == 5)
        Rcon[0] = "10";
    if (round_number == 6)
        Rcon[0] = "20";
    if (round_number == 7)
        Rcon[0] = "40";
    if (round_number == 8)
        Rcon[0] = "80";
    if (round_number == 9)
        Rcon[0] = "1b";
    if (round_number == 10)
        Rcon[0] = "36";


    for (int i = 0; i < 4; i++)
    {
        Rcon[i] = HexToBin(Rcon[i]);
        v[i] = Key[i][3];
    }
    //rotword
    string aux = v[0];
    v[0] = v[1];
    v[1] = v[2];
    v[2] = v[3];
    v[3] = aux;

    //SubBytes
    string lin, col;
    for (int i = 0; i < 4; i++)
    {
        string str = v[i];
        lin = "";
        col = "";
        lin = str[0];
        lin += str[1];
        lin += str[2];
        lin += str[3];

        col = str[4];
        col += str[5];
        col += str[6];
        col += str[7];

        lin = fourBinaryToHex(lin);
        col = fourBinaryToHex(col);

        int lin_int = HexCharToInt(lin[0]);
        int col_int = HexCharToInt(col[0]);
        v[i] = sbox[lin_int][col_int]; // coloana prelucrata dupa subbytes
    }

    //copiem prima coloana din matricea initiala
    string first_column[4];
    for (int i = 0; i < 4; i++)
    {
        first_column[i] = Key[i][0];
    }

    for (int i = 0; i < 4; i++)
    {
        v[i] = xorBetweenStrings(v[i], first_column[i]);
        v[i] = xorBetweenStrings(v[i], Rcon[i]);
        //in v[i] se gaseste prima coloana din cheia  dupa expansion
        newKey[i][0] = v[i];
    }

    for(int i=0;i<4;i++)
        for (int j = 1; j < 4; j++)
        {
            newKey[i][j] = xorBetweenStrings(newKey[i][j - 1], Key[i][j]);
        }

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            Key[i][j] = newKey[i][j];
}

void Cipher(string inputS, string keyS) {
    string M[4][4], Key[4][4];
    putInBiArray(inputS, M);
    putInBiArray(keyS, Key);
    hexBiArray_to_binaryBiArray(M);
    hexBiArray_to_binaryBiArray(Key);
    string sbox[16][16];
    create_sBox(sbox);
    
    //runda 0
    cout << "matricea la runda 0 (inainte de 1-9): \n";
    PrintBiArray(M);

    cout << "Cheia rundei 0 (Cheia initiala) \n";
    PrintBiArray(Key);

    AddRoundKey(M, Key);

   

    //rundele 1-9
    for (int round = 1; round <= 9; round++) {
        cout << "runda " << round << "\n";
        cout << "matricea la inceput de runda: \n";
        PrintBiArray(M);

        SubBytes(M, sbox);
        cout << "matricea dupa SubBytes: \n";
        PrintBiArray(M);

        ShiftRows(M);
        cout << "matricea dupa ShiftRows: \n";
        PrintBiArray(M);

        MixColumns(M);
        cout << "matricea dupa MixColumns: \n";
        PrintBiArray(M);

        KeyExpansion(Key, sbox, round);
        cout << "cheia rundei:\n";
        PrintBiArray(Key);
        AddRoundKey(M, Key);
    }

    //runda 10
    cout << "matricea la runda 10 : \n";
    PrintBiArray(M);

    SubBytes(M, sbox);
    cout << "matricea dupa SubBytes: \n";
    PrintBiArray(M);

    ShiftRows(M);
    cout << "matricea dupa ShiftRows: \n";
    PrintBiArray(M);

    KeyExpansion(Key, sbox, 10);
    cout << "Cheia rundei 10 \n";
    PrintBiArray(Key);
    AddRoundKey(M, Key);

    cout << "matricea output: \n";
    PrintBiArray(M);
    
}

int main()
{
    string inputS = "32 43 f6 a8 88 5a 30 8d 31 31 98 a2 e0 37 07 34";
    string keyS = "2b 7e 15 16 28 ae d2 a6 ab f7 15 88 09 cf 4f 3c";
    Cipher(inputS, keyS);
}

