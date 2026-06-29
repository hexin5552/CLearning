/**
 * @author Hexin
 * @version 1.0
 */
//数组指针的表示方法
int main(void) {
    int grid[30][100];
    //1
    &grid[22][56];
    //2
    &grid[22][0];
    grid[22][0]; *(grid + 22);

    //3
    &grid[0][0];
    grid[0];
    *(grid);

    return 0;
}