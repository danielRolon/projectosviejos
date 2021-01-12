#include <game/raycasting.h>

#include <math.h>
#include <renderer2d.h>

void rayCasting(int* map, int dScreenWidth, int dScreenHeight, float FOV, float aPlayer,
                float xPlayer, float yPlayer, int dWidthMap, int dHeightMap, float tTile, float tTileDraw)
{
    for (float xsum = 0; xsum < dScreenWidth; xsum++)
    {
        float aRay = (aPlayer - FOV/2.0f) + ((float)xsum / (float) dScreenWidth) * FOV;
        float xRay = xPlayer;
        float yRay = yPlayer;

        float xStep = cos(aRay);
        float yStep = sin(aRay);

        int xMap = floor(xRay / tTile);
        int yMap = floor(yRay / tTile);

        while (!map[(xMap + yMap * dWidthMap)] == 1)
        {
            xRay += xStep;
            yRay += yStep;

            xMap = floor(xRay / tTile);
            yMap = floor(yRay / tTile);

            
        }

        // Distance in tam tile (tamaño real)
        float ca = abs(xPlayer - xRay);
        float co = abs(yPlayer - yRay);
        float fDistance = sqrt(ca*ca + co*co);

        // Distance fixed (distancia arreglada)
            ca = abs(xPlayer/tTile - xRay/tTile);
            co = abs(yPlayer/tTile - yRay/tTile);
        float fDistancFixed = sqrt(ca*ca + co*co);


        // Calcule
        
        //  Fish eye effect fixed
        fDistance     = fDistance     * (cos(aPlayer - aRay));
        fDistancFixed = fDistancFixed * (cos(aPlayer - aRay));

        float fCeiling = ( (float)dScreenHeight/2.0f) - ((float)dScreenHeight / (float)fDistance  * (tTile/2));
        float fFloor   = dScreenHeight - fCeiling;

        // Draw  column
        float fAlpha = (1.0f / (fDistancFixed/3) );
        Renderer2D::SetAlpha(fAlpha);
        Renderer2D::SetColor(0.0f, 0.0f, 0.0f);
        //Renderer2D::DrawTexture(xsum, fFloor, 1, abs(dScreenHeight/2-fCeiling), 0, 0, 8.0f/16.0f, 16.0f/16.0f, "Nave");
        Renderer2D::DrawLine(xsum, fFloor, xsum, fCeiling);
        Renderer2D::SetAlpha(1.0f);

        // Draw ray
        float xPlayerDraw = xPlayer/tTile*tTileDraw;
        float yPlayerDraw = yPlayer/tTile*tTileDraw;
        float xRayDraw    = xRay/tTile*tTileDraw;
        float yRayDraw    = yRay/tTile*tTileDraw;


        if (xsum == dScreenHeight/2)
        {
            printf("yRayD: %f\n", yRayDraw);
        }

        Renderer2D::SetColor(1.0f, 0.0f, 0.0f);
        Renderer2D::DrawRect(0.0f, 0.0f, 5.0f, 5.0f);
    }
}