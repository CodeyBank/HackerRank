import math

def mainfunction():
    # str = input("Please type string: \n")
    # string = "Does this string satisfy the conditions"
    string = "if man was meant to stay on the ground god would have given us roots"
    # remove all spaces and new line characters
    string = string.replace(" ","")
    #print(string)

    # store the length of string
    lengthOfString = len(string)
    # print("length of string: {}".format(l_string))

    # get square root of string
    tmp = math.sqrt(lengthOfString);
    [Upper, Lower] = [math.ceil(tmp), math.floor(tmp)]
    # print("Upper: {} Lower: {}".format(Upper, Lower))

    # compute how many rows and columns will be needed
    ## for upper
    nrowsUpper = getNumberOfRows(lengthOfString,Upper)
    ncolsUpper = Upper
    # print(nrowsUpper * ncolsUpper)

    nrowsLower = getNumberOfRows(lengthOfString, Lower)
    ncolsLower = Lower
    # print(ncolsLower * nrowsLower)
    
    # get which of both options satisfy conditions rows*cols>=L and min
    nrows, ncols = satisfiesCondition([nrowsUpper, ncolsUpper], [nrowsLower, ncolsLower], lengthOfString)
    # print(result)

    # print the string
    newString = ""
    index = 1

    for row in range(nrows):
        for col in range(ncols):
            if (index>lengthOfString):
                break
            # newString += (str(index) + "\t")
            newString += string[index-1]
            index +=1
        newString += "\n"
    
    print(newString)
    encrypted = ""

    for col in range(1, ncols+1):
        for row in range(1,nrows+1):
            index = getIndex(row,col,ncols)
            if(index > lengthOfString):
                break
            encrypted += string[index-1] 
        encrypted += " "
    print(encrypted)


def satisfiesCondition(upperlist, lowerlist, lengthOfString):
    # unpack the parameters
    nrowUpper_local, ncolUpper_local  = upperlist
    nrowLower_local, ncolLower_local = lowerlist

    # product = row * col
    uppSqr  = nrowUpper_local*ncolUpper_local
    loweSqr = nrowLower_local*ncolLower_local

    # list for storing the option that satisfies the condition row*col >= L and min of both options

    if uppSqr >= lengthOfString:
        if (uppSqr < loweSqr):
            return upperlist
        if loweSqr == uppSqr:
            return upperlist
         
    if loweSqr >= lengthOfString:
        if (uppSqr > loweSqr):
            return lowerlist
        if loweSqr == uppSqr:
            return upperlist


def getNumberOfRows(lengthOfString, options):
    rows = lengthOfString//options
    if (lengthOfString % options) != 0:
        return rows + 1
    else:
        return rows
    
def getIndex(row, col, ncols):
    return col + (ncols * (row-1))

if (__name__ == "__main__"):
    mainfunction()