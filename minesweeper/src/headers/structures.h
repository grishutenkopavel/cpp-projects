#pragma once

typedef struct{
    int width;
    int height;
}  WindowSize;

typedef struct{
    int mapW;
    int mapH;
}  MapSize;

typedef struct {
    bool mine;
    bool flag;
    bool open;
    int cntAround;
} TCell;
