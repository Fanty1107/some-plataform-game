#include <raylib.h>
#include <iostream>
#include <string_view>

using namespace std;
namespace LOG {
    enum LEVEL{
        HIGH,
        MEDIUM,
        LOW,
    };
    string_view level_to_str(LEVEL l){
        switch (l) {
            case HIGH:
                return "HIGH";
            case MEDIUM:
                return "MEDIUM";
            case LOW:
                return "LOW";
        }
    }

    struct PRINT{
        const char *messages;
        LEVEL warning;

        PRINT(const char *m, LEVEL w) : messages(m), warning(w){
            cout <<"[" <<level_to_str(warning) << "]" << ": " << messages << endl;
        }
    };
}

struct Window{
    int width;
    int height;
    const char *title;
    Window(int w, int h, const char *t) : width(w), height(h), title(t){
        InitWindow(width, height, title);
    };
    ~Window(){
        CloseWindow();
    }
};
struct Game{
    Window *win;
};

int main(){
    Window w(800,800,"Teste");
    LOG::PRINT("Testing", LOG::LEVEL::HIGH);
    while(!WindowShouldClose()){
       BeginDrawing();
        ClearBackground(RAYWHITE);
       EndDrawing();
    }
    return 0;
}
