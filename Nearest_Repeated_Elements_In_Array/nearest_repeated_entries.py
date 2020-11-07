def Nearest_Element(Paragraph):
    Distance_Dict = {} #Dictionary that stores the nearest distance between two instances of each 'key' (i.e. word)

    Arrsize = len(Paragraph)

    for idx in range(0, Arrsize - 1):
        if Paragraph[idx] not in Distance_Dict:
            Distance_Dict[Paragraph[idx]] = [idx, 100000]

        else:
            Prev_Location = Distance_Dict[Paragraph[idx]][0] #Get the previous location. needed to calculate new minimum distance
            Last_Min_Dist = Distance_Dict[Paragraph[idx]][1]

            New_Dist = idx - Prev_Location
            if New_Dist < Last_Min_Dist:
                Distance_Dict[Paragraph[idx]][0] = idx
                Distance_Dict[Paragraph[idx]][1] = New_Dist


    Min_Dist = 1000000
    closest_words = 'WTF'
    
    for key in Distance_Dict:
        if Distance_Dict[key][1] < Min_Dist:
            Min_Dist = Distance_Dict[key][1]
            closest_words = key


    return Min_Dist



#One_Paragraph = ['All', 'work', 'and', 'no', 'play', 'makes', 'for', 'no', 'work', 'no', 'fun', 'and', 'no', 'results']
One_Paragraph =	['One', 'shot', 'two', 'shot', 'three', 'kill', 'four', 'shot']

Minimal_Distance = Nearest_Element(One_Paragraph)

print('The shortest distance between two identical words is: ', Minimal_Distance)
