#pragma once

#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <Render/Render.h>
#include <math.h>

class Conway
{
public:
    Conway(size_t columns, size_t rows, float tam, size_t* initial_cells)
        : columns(columns), rows(rows), tam(tam)
    {
        cells = new size_t[columns * rows];
        new_cells = new size_t[columns * rows];

        for (size_t i = 0; i < columns * rows; ++i)
        {
            cells[i]     = initial_cells[i];
            new_cells[i] = initial_cells[i];
        }
    }

    ~Conway()
    {
        delete[]cells;
        delete[]new_cells;
    }

    void update()
    {
        for (int y = 0; y < columns; ++y)
        {
            for (int x = 0; x < rows; ++x)
            {
                size_t friends = 0;

                // Añadir amigos y vecinos
                for (int i = -1; i < 2; ++i)
                {
                    for (int j = -1; j < 2; ++j)
                    {
                        int xFriend = floor((x + j + columns) % columns);
                        int yFriend = floor((y + i + rows) % rows);

                        if (i != 0 && j != 0 && cells[xFriend + yFriend * rows] == 1)
                        {
                            ++friends;
                        }
                    }
                }

                new_cells[x + y * rows] = cells[x + y * rows];

                // Reglas de conway
                if (friends == 3)
                    new_cells[x + y * rows] = 1;
 
                if (friends < 2 || friends > 3)
                    new_cells[x + y * rows] = 0;
            }
        }

        //printf("map is: %d\n", cells[4 + 3 * rows]);

        // Actualizar celulas
        for (size_t i = 0; i < columns * rows; ++i)
        {
            cells[i] = new_cells[i];
        }
    }

    void draw(Render& render)
    {
        // Draw cells
        for (int y = 0; y < columns; ++y)
        {
            for (int x = 0; x < rows; ++x)
            {
                if (cells[x + y * rows] == 1) 
                    render.addQuad(x * tam, y * tam, tam, tam, &c_live);
                else  render.addQuad(x * tam, y * tam, tam, tam, &c_dead);
            }
        }
        
    }
private:
    float tam = 0;
    size_t* cells = nullptr;
    size_t* new_cells = nullptr;
    size_t columns = 0;
    size_t rows = 0;
    Color c_live{1, 1, 1}, c_dead{0, 0, 0.2};
};