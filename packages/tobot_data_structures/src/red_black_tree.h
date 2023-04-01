#pragma once

namespace Tobot::DataStructures {

    template <typename T>
    class RedBlackTree {
        public:
            struct Node {
                    T value;
                    Node * left;
                    Node * right;
                    Node * parent;
                    bool isRed;
            };
            RedBlackTree();
            ~RedBlackTree();
            void Insert(T value);
            void Delete(T value);
            bool Contains(T value);
            Node * Search(T value);
            void Print();

        private:
            Node * root;
            Node * nil;
            void LeftRotate(Node * x);
            void RightRotate(Node * x);
            void InsertFixup(Node * z);
            void DeleteFixup(Node * x);
            void Transplant(Node * u, Node * v);
            Node * Minimum(Node * x);
            Node * Maximum(Node * x);
            Node * Successor(Node * x);
            Node * Predecessor(Node * x);
            void Print(Node * x);
    };

    template <typename T>
    RedBlackTree<T>::RedBlackTree() {
        this->nil = new Node;
        this->nil->left = nullptr;
        this->nil->right = nullptr;
        this->nil->parent = nullptr;
        this->nil->isRed = false;
        this->root = this->nil;
    }

    template <typename T>
    RedBlackTree<T>::~RedBlackTree() {
        delete this->nil;
    }

    template <typename T>
    void RedBlackTree<T>::LeftRotate(Node * x) {
        Node * y = x->right;
        x->right = y->left;
        if (y->left != this->nil) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == this->nil) {
            this->root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    template <typename T>
    void RedBlackTree<T>::RightRotate(Node * x) {
        Node * y = x->left;
        x->left = y->right;
        if (y->right != this->nil) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == this->nil) {
            this->root = y;
        } else if (x == x->parent->right) {
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }

    template <typename T>
    void RedBlackTree<T>::InsertFixup(Node * z) {
        while (z->parent->isRed) {
            if (z->parent == z->parent->parent->left) {
                Node * y = z->parent->parent->right;
                if (y->isRed) {
                    z->parent->isRed = false;
                    y->isRed = false;
                    z->parent->parent->isRed = true;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        this->LeftRotate(z);
                    }
                    z->parent->isRed = false;
                    z->parent->parent->isRed = true;
                    this->RightRotate(z->parent->parent);
                }
            } else {
                Node * y = z->parent->parent->left;
                if (y->isRed) {
                    z->parent->isRed = false;
                    y->isRed = false;
                    z->parent->parent->isRed = true;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        this->RightRotate(z);
                    }
                    z->parent->isRed = false;
                    z->parent->parent->isRed = true;
                    this->LeftRotate(z->parent->parent);
                }
            }
        }
        this->root->isRed = false;
    }

    template <typename T>
    void RedBlackTree<T>::Insert(T value) {
        Node * z = new Node;
        z->value = value;
        z->left = this->nil;
        z->right = this->nil;
        z->parent = this->nil;
        z->isRed = true;
        Node * y = this->nil;
        Node * x = this->root;
        while (x != this->nil) {
            y = x;
            if (z->value < x->value) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        z->parent = y;
        if (y == this->nil) {
            this->root = z;
        } else if (z->value < y->value) {
            y->left = z;
        } else {
            y->right = z;
        }
        this->InsertFixup(z);
    }

    template <typename T>
    void RedBlackTree<T>::Delete(T value) {
        Node * z = this->root;
        while (z != this->nil && z->value != value) {
            if (value < z->value) {
                z = z->left;
            } else {
                z = z->right;
            }
        }
        if (z == this->nil) {
            return;
        }
        Node * y = z;
        Node * x;
        bool yOriginalColor = y->isRed;
        if (z->left == this->nil) {
            x = z->right;
            this->Transplant(z, z->right);
        } else if (z->right == this->nil) {
            x = z->left;
            this->Transplant(z, z->left);
        } else {
            y = this->Minimum(z->right);
            yOriginalColor = y->isRed;
            x = y->right;
            if (y->parent == z) {
                x->parent = y;
            } else {
                this->Transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            this->Transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->isRed = z->isRed;
        }
        if (!yOriginalColor) {
            this->DeleteFixup(x);
        }
        delete z;
    }

    template <typename T>
    void RedBlackTree<T>::DeleteFixup(Node * x) {
        while (x != this->root && !x->isRed) {
            if (x == x->parent->left) {
                Node * w = x->parent->right;
                if (w->isRed) {
                    w->isRed = false;
                    x->parent->isRed = true;
                    this->LeftRotate(x->parent);
                    w = x->parent->right;
                }
                if (!w->left->isRed && !w->right->isRed) {
                    w->isRed = true;
                    x = x->parent;
                } else {
                    if (!w->right->isRed) {
                        w->left->isRed = false;
                        w->isRed = true;
                        this->RightRotate(w);
                        w = x->parent->right;
                    }
                    w->isRed = x->parent->isRed;
                    x->parent->isRed = false;
                    w->right->isRed = false;
                    this->LeftRotate(x->parent);
                    x = this->root;
                }
            } else {
                Node * w = x->parent->left;
                if (w->isRed) {
                    w->isRed = false;
                    x->parent->isRed = true;
                    this->RightRotate(x->parent);
                    w = x->parent->left;
                }
                if (!w->right->isRed && !w->left->isRed) {
                    w->isRed = true;
                    x = x->parent;
                } else {
                    if (!w->left->isRed) {
                        w->right->isRed = false;
                        w->isRed = true;
                        this->LeftRotate(w);
                        w = x->parent->left;
                    }
                    w->isRed = x->parent->isRed;
                    x->parent->isRed = false;
                    w->left->isRed = false;
                    this->RightRotate(x->parent);
                    x = this->root;
                }
            }
        }
        x->isRed = false;
    }

    template <typename T>
    Tobot::DataStructures::RedBlackTree<T>::Node * RedBlackTree<T>::Search(T value) {
        Node * x = this->root;
        while (x != this->nil && x->value != value) {
            if (value < x->value) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        if (x->value != value) {
            return nullptr;
        }
        return x;
    }

    template <typename T>
    bool RedBlackTree<T>::Contains(T value) {
        Node * x = this->root;
        while (x != this->nil && x->value != value) {
            if (value < x->value) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        if (x->value != value) {
            return false;
        }
        return x;
    }

    template <typename T>
    void RedBlackTree<T>::Transplant(Node * u, Node * v) {
        if (u->parent == this->nil) {
            this->root = v;
        } else if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    template <typename T>
    Tobot::DataStructures::RedBlackTree<T>::Node * RedBlackTree<T>::Minimum(Node * x) {
        while (x->left != this->nil) {
            x = x->left;
        }
        return x;
    }

    template <typename T>
    Tobot::DataStructures::RedBlackTree<T>::Node * RedBlackTree<T>::Maximum(Node * x) {
        while (x->right != this->nil) {
            x = x->right;
        }
        return x;
    }

    template <typename T>
    Tobot::DataStructures::RedBlackTree<T>::Node * RedBlackTree<T>::Successor(Node * x) {
        if (x->right != this->nil) {
            return this->Minimum(x->right);
        }
        Node * y = x->parent;
        while (y != this->nil && x == y->right) {
            x = y;
            y = y->parent;
        }
        return y;
    }

    template <typename T>
    Tobot::DataStructures::RedBlackTree<T>::Node * RedBlackTree<T>::Predecessor(Node * x) {
        if (x->left != this->nil) {
            return this->Maximum(x->left);
        }
        Node * y = x->parent;
        while (y != this->nil && x == y->left) {
            x = y;
            y = y->parent;
        }
        return y;
    }

    template <typename T>
    void RedBlackTree<T>::Print() {
        this->Print(this->root);
        std::cout << std::endl;
    }

    template <typename T>
    void RedBlackTree<T>::Print(Node * x) {
        if (x != this->nil) {
            this->Print(x->left);
            std::cout << x->value << " ";
            this->Print(x->right);
        }
    }

} // namespace Tobot::DataStructures