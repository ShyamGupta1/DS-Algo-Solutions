class Solution
{
public:
    int finalPositionOfSnake(int n, vector<string> &commands)
    {

        int row = 0, col = 0;
        for (int i = 0; i < commands.size(); i++)
        {
            if (commands[i] == "UP")
                row -= 1;
            else if (commands[i] == "DOWN")
                row += 1;
            else if (commands[i] == "LEFT")
                col -= 1;
            else
                col += 1;
        }
        return row * n + col;
    }
};