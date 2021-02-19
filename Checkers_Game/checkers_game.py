def Max_Pieces_Conquered(Initial_Config):
    if len(Initial_Config) < 3:
        return 0

    IsValid = [] #Used to store the possible locations the white piece can be in
    Pieces_Taken = [] #Used to keep track of the maximum number of pieces taken if the white piece lands in i, j

    iprime = 0
    jprime = 0
    
    for i in range(len(Initial_Config)):
        Dummy_IsValid = []
        Dummy_PiecesTaken = []
        
        for j in range(len(Initial_Config[i])):
            if Initial_Config[i][j] == 'O':
                iprime = i
                jprime = j

            Dummy_IsValid.append(0)
            Dummy_PiecesTaken.append(0)
            
        IsValid.append(Dummy_IsValid)
        Pieces_Taken.append(Dummy_PiecesTaken)


    IsValid[iprime][jprime] = 1
    #All the solution matrices are now filled

    #print('i prime is: ', iprime, '\n')
    #print('j prime is: ', jprime, '\n')

   
    #print('The IsValid Matrix is: \n')
    #for i in IsValid:
    #    for j in i:
    #        print(j, end=' ')
    #    print('\n')


    #print('\n The Pieces Taken Matrix is: \n')
    #for i in Pieces_Taken:
    #    for j in i:
    #        print(j, end=' ')
    #    print('\n')
    
    Max_Pieces_Taken = 0
    
    for i in range(len(IsValid)):
        for j in range(len(IsValid[i])):

            print('Value of i: ', i, '. j: ', j)
            
            if i < 2: continue
            
            if j - 2 >= 0:
                if IsValid[i - 2][j - 2] == 1 and Initial_Config[i - 1][j - 1] == 'X' and Initial_Config[i][j] == '.':
                    IsValid[i][j] = 1
                    print('Pieces taken in ', i - 2, ', ', j - 2, ' is: ', Pieces_Taken[i - 2][j - 2])
                    pieces_taken_tmp = Pieces_Taken[i - 2][j - 2] + 1
                    Pieces_Taken[i][j] = pieces_taken_tmp
                    
                    if(pieces_taken_tmp > Max_Pieces_Taken):
                        Max_Pieces_Taken = pieces_taken_tmp



            if j + 2 < len(Initial_Config):
                if IsValid[i - 2][j + 2] == 1 and Initial_Config[i - 1][j + 1] == 'X' and Initial_Config[i][j] == '.':
                    IsValid[i][j] = 1
                    print('Pieces taken in ', i - 2, ', ', j + 2, ' is: ', Pieces_Taken[i - 2][j + 2])
                    pieces_taken_tmp = Pieces_Taken[i - 2][j + 2] + 1

                    Pieces_Taken[i][j] = pieces_taken_tmp

                    if(pieces_taken_tmp > Max_Pieces_Taken):
                        Max_Pieces_Taken = pieces_taken_tmp


    #print('\n\n The board has been evaluated\n\n')

    #print('The IsValid Matrix is: \n')
    #for i in IsValid:
    #    for j in i:
    #        print(j, end=' ')
    #    print('\n')


    #print('\n The Pieces Taken Matrix is: \n')
    #for i in Pieces_Taken:
    #    for j in i:
    #        print(j, end=' ')
    #    print('\n')
 
    return Max_Pieces_Taken


#checkers_board = ['O....', '.X...', '.....', '.X...', '.....']
checkers_board = ['..O...', '.X.X..', 'X.....', '...X..', '..X...', '..X...']
answer = Max_Pieces_Conquered(checkers_board)

print('Max Pieces taken: ', answer)
