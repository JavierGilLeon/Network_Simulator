#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

#include "common.h"
#include "board.h"
#include "event.h"
#include "window.h"

int main(int argc, char* argv[])
{


    //-------------------------------- WINDOW CONFIGS -----------------------------
//  InitWindow(SCREEN_WIDTH,SCREEN_HEIGHT, "Simulador de Redes");
    SetTargetFPS(60);



    int filePathCounter = 0;

    char* filePath;
    filePath = (char *)RL_CALLOC(1, 1);


    Rectangle fileDropper = {
        20, 
        40, 
        SCREEN_WIDTH*0.95f, 
        SCREEN_HEIGHT/10
    };

    Rectangle modeSelect = {
        fileDropper.x, 
        (fileDropper.y + fileDropper.height + 20), 
        fileDropper.width/2, 
        (SCREEN_HEIGHT*3)/4
    };

    Rectangle slaveRec = {
        (modeSelect.x + modeSelect.width) + 20, 
        modeSelect.y, 
        (fileDropper.width - modeSelect.width - 20), 
        modeSelect.height/10
    };

    Rectangle cycleRec = {
        (modeSelect.x + modeSelect.width) + 20, 
        modeSelect.y + slaveRec.height + 20, 
        (fileDropper.width - modeSelect.width - 20), 
        modeSelect.height/10
    };

    Rectangle timeRec = {
        (modeSelect.x + modeSelect.width) + 20, 
        cycleRec.y + cycleRec.height + 20, 
        (fileDropper.width - modeSelect.width - 20), 
        modeSelect.height/10
    };

    Rectangle runConfig = {
        (modeSelect.x + modeSelect.width) + 20, 
        (modeSelect.y + modeSelect.height) - (timeRec.height*2),
        timeRec.width/2 - 10, 
        timeRec.height*2
    };

    Rectangle runFile = {
        (runConfig.x + runConfig.width) + 20, 
        (modeSelect.y + modeSelect.height) - (timeRec.height*2),
        timeRec.width/2 - 10, 
        timeRec.height*2
    };
    //-----------------------------------------------------------------------------

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    srand(t->tm_sec);


    int numSlaves = atol(argv[1]);
    int numCycles = atol(argv[2]);
    int mode      = atoi(argv[3]);

    fileLog = fopen("run.log","w");
    fileCSV = fopen("run.csv","w");

    while(numCycles > 0){
        switch (mode)
        {
        case 0:
            CommActiveWait(numSlaves);
            break;
        case 1: 
            CommActiveWaitBroadcast(numSlaves);
            break;
        default: 
            printf("Modo invalido\n");
            return 1;
            break;
        }

    fprintf(fileLog,"---------------------\n");
    printf("---------------------\n");
    int i = numEvents;
    while(numEvents > 0)
    {
        handleEvent(evQueue[i - numEvents]);
    }

    numCycles--;
    }


   /* while(!WindowShouldClose()){

        // ------------------- COMPATIBILIDAD CON ARRASTRAR ARCHIVOS ----------------------------
        if(IsFileDropped)
        {
            FilePathList droppedFiles = LoadDroppedFiles();

            for(int i = 0, offset = filePathCounter; i < (int)droppedFiles.count; i++)
            {
                if(filePathCounter < (MAX_FILEPATH_RECORDED - 1))
                {
                    TextCopy(filePath, droppedFiles.paths[0]);
                    filePathCounter++;
                }
            }
            UnloadDroppedFiles(droppedFiles);
        }
        // --------------------------------------------------------------------------------------

        BeginDrawing();
        ClearBackground(RAYWHITE);


        DrawRectangleRec(modeSelect, Fade(LIGHTGRAY, 0.5f));
        DrawRectangleRec(slaveRec,   Fade(LIGHTGRAY, 0.5f));
        DrawRectangleRec(cycleRec,   Fade(LIGHTGRAY, 0.5f));
        DrawRectangleRec(timeRec,    Fade(LIGHTGRAY, 0.5f));
        DrawRectangleRec(runConfig,  Fade(LIGHTGRAY, 0.5f));
        DrawRectangleRec(runFile,    Fade(LIGHTGRAY, 0.5f));

        DrawText("Run From File",  (runFile.x + 20), (runFile.y + runFile.height/2), 25, DARKGRAY);
        DrawText("Run From Config",(runConfig.x + 20), (runConfig.y + runConfig.height/2), 25, DARKGRAY);


        // ------------------- COMPATIBILIDAD CON ARRASTRAR ARCHIVOS (DIBUJAR) ----------------------------
        DrawRectangleRec(fileDropper, Fade(LIGHTGRAY,0.5f));

        if(filePathCounter == 0) DrawText("Drop Files here", (fileDropper.x + fileDropper.height)/2, (fileDropper.y + fileDropper.height)/2, 30, DARKGRAY);
        else                     DrawText(filePath,(fileDropper.x + fileDropper.height)/2, (fileDropper.y + fileDropper.height)/2, 30, GRAY);
        // -------------------------------------------------------------------------------------------------

        EndDrawing();
    }

    for(int i = 0; i < MAX_FILEPATH_RECORDED; i++)
    {
        RL_FREE(filePath);
    }

    CloseWindow();
*/
    fclose(fileLog);
    fclose(fileCSV);
    return 0;
}