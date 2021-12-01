INF = pow(10, 20)

class Class:
    def __init__(self, id_):
        self.students = []
        self.point = 0
        self.id = id_
    
    def insert(self, x):
        self.students.append(x - self.point)
        ind = len(self.students) - 1
        while self.students[ind] < self.students[ind // 2]:
            self.students[ind], self.students[ind//2] = self.students[ind//2], self.students[ind]
            ind //= 2
    
    def add_point(self, x):
        self.students += x

    def delete_min(self):
        if len(self.students) == 0:
            return
        tmp = self.students[len(self.students) - 1]
        self.students[0] = tmp
        self.students.pop()
        ind = 0
        while len(self.students) > ind * 2 + 1:
            left = ind * 2 + 1
            right = ind * 2 + 2
            length = len(self.students)
            if length > right:
                if self.students[right] < self.students[left]:
                    left = right
            if self.students[left] < self.students[ind]:
                self.students[left], self.students[ind] = self.students[ind], self.students[left]
                ind = left
            else:
                break

    def get_min(self):
        if len(self.students) == 0:
            return INF
        return self.students[0] + self.point


n, q = map(int, input().strip().split())
classes = [] 
for i in range(n):
    classes.append(Class(i))

ind_to_class = []
class_heap = []

for i in range(n):
    classes[i].id = i
    ind_to_class.append(i)
    class_heap.append(i)

for i in range(q):
    for j in classes:
        print(j.get_min())

    strings = input().strip().split()
    query = []
    for j in strings:
        query.append(int(j))
    if query[0] == 1:
        class_id = query[1] - 1
        student_point = query[2]
        id_in_heap = ind_to_class[class_id]
        classes[class_id].insert(student_point)
    elif query[0] == 2:
        class_id = query[1] - 1
        point = query[2]
        id_in_heap = ind_to_class[class_id]
        classes[class_id].point += point
    else:
        id_in_heap = 0;
        if(classes[class_heap[id_in_heap]].get_min() == INF):
            print(-1)
        else:
            print(classes[class_heap[id_in_heap]].get_min())
            classes[class_heap[id_in_heap]].delete_min()

    while(id_in_heap > 0):
        father_id = id_in_heap // 2
        if classes[class_heap[father_id]].get_min() > classes[class_heap[id_in_heap]].get_min():
            class_heap[father_id], class_heap[id_in_heap] = class_heap[id_in_heap], class_heap[father_id]
            ind_to_class[classes[father_id].id] = father_id
            ind_to_class[classes[id_in_heap].id] = id_in_heap
            id_in_heap = father_id
        else:
            break

    while id_in_heap * 2 + 1 < len(classes):
        son = id_in_heap * 2 + 1
        if son + 1 < len(classes):
            if classes[class_heap[son]].get_min() > classes[class_heap[son + 1]].get_min():
                son += 1
        if classes[class_heap[son]].get_min() < classes[class_heap[id_in_heap]].get_min():
            class_heap[son], class_heap[id_in_heap] = class_heap[id_in_heap], class_heap[son]
            ind_to_class[classes[son].id] = son
            ind_to_class[classes[id_in_heap].id] = id_in_heap
            id_in_heap = son
        else:
            break
