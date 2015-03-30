class Tree:
    def __init__(self):
        self.root = None

    def insert(self, x):
        # arvore nao esta vazia
        if self.root:
            self.root.insert(x)
        # arvore esta vazia
        else:
            self.root = Node(x)

    # procura um elemento com a chave x
    # se x existir, retornar Nodo,
    # se nao existir, retornar None
    def search(self, x):
        if self.root:
            return self.root.search(x)
        else:
            return None




    def __repr__(self):
        return str(self.root)



#vermelho = 1
#preto = 0
class Node:
    def __init__(self, k):
        self.l = None
        self.r = None
        self.k = k
        self.p = None
        self.color = 1

    def vermelho(self):
        return self.color == 1

    def insert(self, x):
        nodo_x = None
        if x > self.k:
            if self.r:
                self.r.insert(x)
            else:
                self.r = Node(x)
                self.r.p = self
                nodo_x = self.r
        elif x < self.k:
            if self.l:
                self.l.insert(x)
            else:
                self.l = Node(x)
                self.l.p = self
                nodo_x = self.l
        if nodo_x:
            nodo_x.balance()


    def balance(self):
        if not self.p:
            self.color = 0
            return
        if not self.p.p:
            self.p.color = 0
            return
        if self.p.vermelho():
            if self.caso4():
                self.resolve_caso4()
                return
            if self.caso3():
                self.resolve_caso3()
            self.resolve_caso2()

    def l_rotate(self):
        self.r.p = self.p

        aux = self.r
        self.r = self.r.l

        self.p = aux
        if self.p.l == self:
            self.p.l = aux
        else:
            self.p.r = aux

    def tio(self):
        pass

    def caso4(self):
        return self.tio().vermelho()

    def resolve_caso4(self):
        self.tio().color = 0
        self.p.color = 0
        self.p.p.color = 1
        self.p.balance()

    def caso3(self):
# checar zig zag
        return (self.p.r == self and \
                self.p.p.l == self.p) \
                or \
                (self.p.l == self and \
                self.p.p.r == self.p)

    def resolve_caso3(self):
        if self.p.r == self:
            self.p.r_rotate()
        else:
            self.p.l_rotate()

    def resolve_caso2(self):
        self.p.color = 0
        self.p.p.color = 1
        if self.p.l == self:
            self.p.p.r_rotate()
        else:
            self.p.p.l_rotate()






    def search(self, x):
        if self.k == x:
            return self
        elif self.k > x and self.r:
            return self.r.search(x)
        elif self.k < x and self.l:
            return self.l.search(x)
        else:
            return None

# retorna o menor elemento a partir deste nodo,
# descendo pela arvore
    def minimum(self):
        if self.l:
            return self.l.minimum()
        else:
            return self

# retorna o sucessor do elemento, a partir deste nodo,
# descendo pela arvore
    def sucessor(self):
        if self.r:
            return self.r.minimum()
        elif self.r.p:
            return self.r.p
        else:
            return None


# remove o um nodo da arvore
    def remove(self, x):
        n = self.search(x)
        if n:
            n.remove2()

    def swapch(self, old, new):
        if self.r == old:
            self.r = new
        else:
            self.l = new


    def remove2(self):
        if not self.r and not self.l:
            self.p.swapch(self, None)
        elif self.r:
            self.r.p = self.p
            self.p.swapch(self, self.r)
        elif self.l:
            self.l.p = self.p
            self.p.swapch(self, self.l)
        else:
            s = self.sucessor()
            s.k, self.k = self.k, s.k
            s.remove2()



    def __repr__(self):
        return "T(%s, %d, %s)" % (str(self.l), self.k, str(self.r))


t = Tree()
print(t)

for k in [10, 5, 7, 2]:
    t.insert(k)
    print(t)


def insert(t, x):
    if not t.root:
        t.root = Node(x)
    else:
        aux = t.root
        while True:
            if x > aux.k:
                if not aux.r:
                    aux.r = Node(x)
                    break
                else:
                    aux = aux.r
            elif x < aux.k:
                if not aux.l:
                    aux.l = Node(x)
                    break
                else:
                    aux = aux.l
            else:
                break








