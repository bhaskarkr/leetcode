class TextEditor {
public:
    int cursor = 0;
    string l, r;
    TextEditor() {
    }
    
    void addText(string text) {
        l += text;
    }
    
    int deleteText(int k) {
        int K = k;
        while(K > 0 && !l.empty()) {
            l.pop_back();
            K--;
        }
        return k - K;
    }
    
    string cursorLeft(int k) {
        while(k > 0 && !l.empty()) {
            r.push_back(l.back());
            l.pop_back();
            k--;
        }
        return l.substr(max(0, (int)l.length() - 10), 10);
    }
    
    string cursorRight(int k) {
        while(k > 0 && !r.empty()) {
            l.push_back(r.back());
            r.pop_back();
            k--;
        }
        return l.substr(max(0, (int)l.length() - 10), 10);
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */






// Below doesn't pass all the test cases 
class TextEditor {
public:
    int cursor = 0;
    string s;
    TextEditor() {
    }
    
    void addText(string text) {
        s = s.substr(0, cursor) + text + s.substr(cursor);
        cursor += text.length();
    }
    
    int deleteText(int k) {
        string temp = s;
        int t = cursor;
        if(k >= cursor)
            k = cursor;
        s = s.substr(0, cursor - k) + s.substr(cursor);
        cursor -= k;
        return k;
    }
    
    string cursorLeft(int k) {
        if(k >= cursor) {
            k = cursor;
        }
        cursor -= k;
        return s.substr(max(0, cursor - 10), min(10, (int)cursor));
    }
    
    string cursorRight(int k) {
        // return "";
        if(cursor + k >= s.length()) {
            cursor = s.length();
        } else {
            cursor += k;
        }
        return s.substr(max(0, cursor - 10), cursor - max(0, cursor - 10));
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */

