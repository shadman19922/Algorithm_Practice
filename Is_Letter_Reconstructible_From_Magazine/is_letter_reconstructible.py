def IsLetterReconstructible(CharsInLetter: str, CharsInMagazine: str):
    Letter_Dict = {}
    #Magazine_Dict = {}

    x = True
    
    for letter in CharsInLetter:
        if letter in Letter_Dict:
            a = Letter_Dict[letter]
            a = a+1
            Letter_Dict[letter] = a
        else:
            Letter_Dict[letter] = 1

    for letter in CharsInMagazine:
        if letter in Letter_Dict:
            a = Letter_Dict[letter]
            a =	a - 1
            Letter_Dict[letter] = a
        else:
            x = False
            return x

    for key in Letter_Dict:
        if(Letter_Dict[key] != 0):
            x =	False
            return x
        else:
            continue

    return x


s1 = "kill bills"
s2 = "bill kill"

Answer = IsLetterReconstructible(s1, s2)

print('s1 is reconstructible from s2: ', Answer)
