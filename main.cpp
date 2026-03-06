#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;
// working with c-strings and functions for c-string
int main() {
    char text[256];

    cout<<"Input line: ";
    cin.getline(text, 256);
    char text1[256]; strcpy(text1, text);
    cout<<text<<endl;
    int i;
    int up = 0, lo = 0, d = 0, w = 0;
    for(i = 0; i< strlen(text); i++){
        if(isupper(text[i])){
            up = up + 1;
        }
        if(islower(text[i])){
            lo = lo + 1;
        }
        if(isdigit(text[i])){
            d = d + 1;
        }
        if(isspace(text[i])){
            w = w + 1;
        }
    }
    cout<<"Upper="<<up<<" ";
    cout<<"Lower="<<lo<<" ";
    cout<<"Digits="<<d<<" ";
    cout<<"Space="<<w<<" "<<endl;

    cout<<"Inverted: ";
    for(i = 0; i < strlen(text); i++){
        if(isupper(text[i])){
            text[i] = tolower(text[i]);
            cout<<text[i];
        }
        else if(islower(text[i])){
            text[i] = toupper(text[i]);
            cout<<text[i];
        }
        else{
            cout<<text[i];
        }
    }
    cout<<endl;
    char line[256];
    char tag[12];

    cout<<"Tag: ";
    cin.getline(tag, 12);
    strcpy(line, text1);

    cout<<"labeled:";
    char labeled[300];
    strcpy(labeled, tag);
    strcat(labeled, line);
    cout<<labeled<<endl;

    cout<<"Needle: ";
    char needle[256]; cin.getline(needle, 256);
    char *ptr = strstr(labeled, needle);
    int index;
    if(ptr!=nullptr){
        index = (int)(ptr-labeled);
    }
    else{
        index = -1;
    }
    cout<<"Index of needle: "<<index<<endl;

    char token[256];
    cout<<"int token: ";
    cin.getline(token, 10);
    int t; t = atoi(token);
    cout<<"atoi="<<t;
}
