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

// void cursorRight(int k) Moves the cursor to the right k times. Equivalent to pressing the right arrow key on a keyboard.

// string fullText() Returns all the text from the start to the finish.

// string showText(int k) Returns the next k characters to the right of the cursor.



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
  
    void addT(string& text){                            //Function call
        this->text.insert(cursor, text);                //Insert at cursor position
        cursor += text.length();                        //Update cursor value
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


//Find cursor

    int findCursor(){                                    //Function call
        return cursor;                                   //Found cursor
    }



//
    void cursorLeft(int k) {
        if(k > cursor)
            cursor = 0;
        cursor = cursor-k;
            }

    void cursorRight(int k) {
        cursor = std::min(cursor + k, static_cast<int>(text.length()));
    }

    std::string fullText() const {
        return text;
    }

    std::string showText(int k) const {
        int endIndex = std::min(cursor + k, static_cast<int>(text.length()));
        return text.substr(cursor, endIndex - cursor);
    }
};





}

