if __name__ == '__main__':
    # create the list

    students = []
    for _ in range(int(input())):
        name = input()
        score = float(input())
        students.append([name, score])

    # students.sort(key= lambda score: score[1])
    # remove the minimum
    minval = min(students,key=lambda students: students[1])
    listwWithoutMin = [[name, score] for [name, score] in students if score > minval[1]]
    listwWithoutMin.sort(key=lambda name: name[0])
    newMinVal = min(listwWithoutMin,key=lambda std: std[1])

    for name , score in listwWithoutMin:
        if score == newMinVal[1]:
            print(name)

