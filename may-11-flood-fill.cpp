// https://leetcode.com/problems/flood-fill/

void paint(vector<vector<int>>& image, int r, int c, int newColor, int oldColor)
{
    image[r][c] = newColor;
    if (r > 0 && image[r - 1][c] == oldColor) paint(image, r - 1, c, newColor, oldColor);
    if (c > 0 && image[r][c - 1] == oldColor) paint(image, r, c - 1, newColor, oldColor);
    if (r < image.size() - 1 && image[r + 1][c] == oldColor) paint(image, r + 1, c, newColor, oldColor);
    if (c < image[0].size() - 1 && image[r][c + 1] == oldColor) paint(image, r, c + 1, newColor, oldColor);
}

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if (newColor == oldColor) return image;
        paint(image, sr, sc, newColor, oldColor);
        return image;
    }
};