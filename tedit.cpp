
#include <iostream>
#include <string>
using namespace std;


class TextEditor{

protected:
    string text;
    int cursor;

public:


//INITIALISE
    TextEditor(){
        cursor=0;
        text="";
    }


//Insert Text using String Library
  
    void addT(string str){                            //Function call
        this->text.insert(cursor, str);                //Insert at cursor position
        cursor += str.length();                        //Update cursor value
    }


//Delete k Letters from the Left

    void deleteT(int k){                                //Function call        
        if (k>cursor){                                  //Special condition check
            text.erase(0, cursor);                        //Remove all in special condition
            cursor = 0;                                   //Reset cursor in special condition
            return;
            } 
        
        text.erase(cursor - k, k);                        //Remove data from cursor position minus K to cursor position
        cursor -= k;                                      //Update cursor position
    }


//Delete 1 Letters from the Left

    void backspace(){                                   //Function call
        deleteT(1);                                     //??
    }                                                   


//Find Cursor

    int findCursor(){                                    //Function call
        return cursor;                                   //Found cursor
    }



//Move Cursor to the Left/Right
    void cursorLeft(int k) {
        if(k > cursor)
            {
                cursor = 0; 
                return;
            }
        cursor = cursor-k;
    }

    void cursorRight(int k) {
        if(k+cursor > text.length())
            {
                cursor=text.length();
                return;
            }
        cursor=cursor+k;
   }



//Display the Full Text
    string fullText(){
        cout<<text<<endl;
        return text;
    }


//Display a Partial (k length) Text
    string showText(int k) {

        if( k+cursor > text.length())                           //Check for exceptional case
            k = text.length() - cursor;                         //Update value of k with number of chars on the right that CAN be displayed

        cout<<text.substr(cursor, k);
        return text.substr(cursor, k);
        
    }
};



int main() {
    
    TextEditor editor;
    
    editor.addT("Hello World");
    editor.fullText();
    
    editor.backspace();
    editor.fullText();

    editor.cursorLeft(2);
    editor.deleteT(3);
    editor.fullText();

    editor.addT("Bellow");
    editor.cursorRight(3);
    
    editor.fullText();

    editor.showText(4);

    return 0;
}


