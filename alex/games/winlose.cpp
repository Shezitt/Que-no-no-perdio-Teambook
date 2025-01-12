// transverse all posible paths and retrieve {win, lose} variables
// this shows that there is a game where a player could control the game (win and lose).
pair<int,int> f(int i = 0) {
    int x = 0, y = 0, ok = 0; 
    for (int j = 0; j<26; j++) 
        if (tre[i][j]) {
            pair<int,int> z = f(tre[i][j]); 
            x|=!z.F, y |= !z.S; 
            ok = 1;
        }
    if (!ok) x = 0, y = 1;
    return {x, y};
}