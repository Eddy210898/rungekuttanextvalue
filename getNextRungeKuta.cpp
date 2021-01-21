float getXValue(int kValue, float x, float dX)
{
    if (kValue == 1)
    {
        return x;
    }
    else if (kValue == 2 || kValue == 3)
    {
        return x + (0.5 * dX);
    }
    else if (kValue == 4)
    {
        return x + dX;
    }
    else
    {
        throw "K value not recognize";
    }
}

float getYValue(int kValue, float y, float dX, float k = 0)
{
    if (kValue == 1)
    {
        return y;
    }
    else if (kValue == 2 || kValue == 3)
    {
        return y + (0.5 * k * dX);
    }
    else if (kValue == 4)
    {
        return y + (k * dX);
    }
    else
    {
        throw "K value not recognize";
    }
}

float getNextRungeKuta(float Xo, float Yo, float dX, float F(float, float, float[]), float args[])
{
    float x = getXValue(1, Xo, dX);
    float y = getYValue(1, Yo, dX);
    float kA = F(x, y, args);
    x = getXValue(2, Xo, dX);
    y = getYValue(2, Yo, dX, kA);
    float kB = F(x, y, args);
    x = getXValue(3, Xo, dX);
    y = getYValue(3, Yo, dX, kA);
    float kC = F(x, y, args);
    x = getXValue(4, Xo, dX);
    y = getYValue(4, Yo, dX, kA);
    float kD = F(x, y, args);
    float kT = kA + kB + kC + kD;
    float newValToAdd = (dX * kT) / 6;
    return Yo + newValToAdd;
}