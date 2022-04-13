#include <iostream>
using namespace std;

string converse(string first, string second)
{
    string output;
    output += second + "->" + first;
    return output;
}

string inverse(string first, string second)
{
    string output;
    bool flag1 = false, flag2 = false;
    int i = 0;

    if (first[0] == '~' || second[0] == '~')
    {
        if (first[0] == '~')
        {
            flag1 = true;
            while (first[i] != '\0')
            {
                first[i] = first[i + 1];
                i++;
            }
        }

        if (second[0] == '~')
        {
            flag2 = true;
            i = 0;
            while (second[i] != '\0')
            {
                second[i] = second[i + 1];
                i++;
            }
        }
    }

    if (flag1 == true && flag2 == true)
        output += first + "->" + second;

    else if (flag1 == true && flag2 == false)
        output += first + "->" + '~' + second;

    else if (flag1 == false && flag2 == true)
        output += '~' + first + "->" + second;

    else
        output += '~' + first + "->" + '~' + second;

    return output;
}

string contrapositive(string first, string second)
{
    string output;
    bool flag1 = false, flag2 = false;
    int i = 0;

    if (first[0] == '~' || second[0] == '~')
    {
        if (first[0] == '~')
        {
            flag1 = true;
            while (first[i] != '\0')
            {
                first[i] = first[i + 1];
                i++;
            }
        }

        if (second[0] == '~')
        {
            flag2 = true;
            i = 0;
            while (second[i] != '\0')
            {
                second[i] = second[i + 1];
                i++;
            }
        }
    }

    if (flag1 == true && flag2 == true)
        output += second + "->" + first;

    else if (flag1 == true && flag2 == false)
        output += '~' + second + "->" + first;

    else if (flag1 == false && flag2 == true)
        output += second + "->" + '~' + first;

    else
        output += '~' + second + "->" + '~' + first;

    return output;
}

void conversions(string first, string second, string form)
{
    string output = "";

    if (form != "Implication")
    {
        if (form == "Converse")
            output = converse(first, second);

        else if (form == "Inverse")
            output = inverse(first, second);

        else if (form == "Contrapositive")
            output = contrapositive(first, second);

        cout << "Implication: " << output << endl;

        int i = 0;
        first = "", second = "";

        while (output[i] != '-')
        {
            first += output[i];
            i++;
        }

        i += 2;

        while (output[i] != '\0')
        {
            second += output[i];
            i++;
        }
    }

    if (form != "Contrapositive")
        cout << "Contrapositive: " << contrapositive(first, second) << endl;

    if (form != "Converse")
        cout << "Converse: " << converse(first, second) << endl;

    if (form != "Inverse")
        cout << "Inverse: " << inverse(first, second) << endl;
}

int main()
{
    string proposition;
    cout << "Enter propostion: ";
    cin >> proposition;

    string form;
    cout << "Enter form: ";
    cin >> form;

    cout << endl;
    int i = 0;
    string first = "", second = "";
    while (proposition[i] != '-')
    {
        first += proposition[i];
        i++;
    }

    i += 2;

    while (proposition[i] != '\0')
    {
        second += proposition[i];
        i++;
    }

    conversions(first, second, form);

    return 0;
}
