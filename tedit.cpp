// Implement the TextEditor class:
Semi done
// TextEditor() Initializes the object with empty text.
Done
// void addText(string text) Appends text to where the cursor is. The cursor ends to the right of text.
Done
// void deleteText(int k) Deletes k characters to the left of the cursor.
Done
// void backspace() Deletes 1 character to the left of the cursor.
Done
// int findCursor() Returns the index position of the cursor.
Done
// void cursorLeft(int k) Moves the cursor to the left k times. Equivalent to pressing the left arrow key on a keyboard
Done
// void cursorRight(int k) Moves the cursor to the right k times. Equivalent to pressing the right arrow key on a keyboard.
Done
// string fullText() Returns all the text from the start to the finish.
Done
// string showText(int k) Returns the next k characters to the right of the cursor.
Done


#include <iostream>
#include <string>
using namespace std;


class TextEdito{

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
  
    void addT(string& str){                            //Function call
        this->text.insert(cursor, str);                //Insert at cursor position
        cursor += str.length();                        //Update cursor value
    }


//Delete k Letters from the Left

    void deleteT(int k){                                //Function call
        
        if (k>cursor){                                  //Special condition check
            text.erase(0, cursor);                        //Remove all in special condition
            cursor = 0;                                   //Reset cursor in special condition
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
            cursor = 0;
        cursor = cursor-k;
    }

    void cursorRight(int k) {
        if(k+cursor > text.length())
            cursor=text.length();
        cursor=cursor+k;
   }



//Display the Full Text
    string fullText(){
        cout<<text;
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





}

