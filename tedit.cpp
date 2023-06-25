// Implement the TextEditor class:
Semi done
// TextEditor() Initializes the object with empty text.
Done
// void addText(string text) Appends text to where the cursor is. The cursor ends to the right of text.
Done
// void deleteText(int k) Deletes k characters to the left of the cursor.

// void backspace() Deletes 1 character to the left of the cursor.

// int findCursor() Returns the index position of the cursor.

// void cursorLeft(int k) Moves the cursor to the left k times. Equivalent to pressing the left arrow key on a keyboard

// void cursorRight(int k) Moves the cursor to the right k times. Equivalent to pressing the right arrow key on a keyboard.

// string fullText() Returns all the text from the start to the finish.

// string showText(int k) Returns the next k characters to the right of the cursor.



#include <iostream>
#include <string>

using namespace std;

class TextEditor {

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
  
    void addText(string& text) {                        //Function call
        this->text.insert(cursor, text);                //Insert at cursor position
        cursor += text.length();                        //Update cursor value
    }


//Delete k Letters from the Left





}

