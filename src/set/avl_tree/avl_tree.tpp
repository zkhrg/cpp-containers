namespace s21 {

template <typename T>
AVLTree<T>::AVLTree() : root(nullptr) {}

template <typename T>
AVLTree<T>::~AVLTree() {
  clear(root);
}

template <typename T>
int AVLTree<T>::height(AVLTreeNode<T>* node) const {
  return node ? node->height : 0;
}

template <typename T>
int AVLTree<T>::balanceFactor(AVLTreeNode<T>* node) const {
  return node ? height(node->left) - height(node->right) : 0;
}

template <typename T>
void AVLTree<T>::updateHeight(AVLTreeNode<T>* node) {
  node->height = 1 + std::max(height(node->left), height(node->right));
}

template <typename T>
AVLTreeNode<T>* AVLTree<T>::rotateRight(AVLTreeNode<T>* y) {
  AVLTreeNode<T>* x = y->left;
  AVLTreeNode<T>* T2 = x->right;

  x->right = y;
  y->left = T2;

  updateHeight(y);
  updateHeight(x);

  return x;
}

template <typename T>
AVLTreeNode<T>* AVLTree<T>::rotateLeft(AVLTreeNode<T>* x) {
  AVLTreeNode<T>* y = x->right;
  AVLTreeNode<T>* T2 = y->left;

  y->left = x;
  x->right = T2;

  updateHeight(x);
  updateHeight(y);

  return y;
}

template <typename T>
void AVLTree<T>::insert(T value) {
  root = insert(root, value);
}

template <typename T>
AVLTreeNode<T>* AVLTree<T>::insert(AVLTreeNode<T>* node, T value) {
  if (node == nullptr) {
    return new AVLTreeNode<T>(value);
  }

  if (value < node->data) {
    node->left = insert(node->left, value);
  } else if (value > node->data) {
    node->right = insert(node->right, value);
  } else {
    return node;
  }

  updateHeight(node);

  int balance = balanceFactor(node);

  if (balance > 1 && value < node->left->data) {
    return rotateRight(node);
  }

  if (balance < -1 && value > node->right->data) {
    return rotateLeft(node);
  }

  if (balance > 1 && value > node->left->data) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
  }

  if (balance < -1 && value < node->right->data) {
    node->right = rotateRight(node->right);
    return rotateLeft(node);
  }

  return node;
}

template <typename T>
AVLTreeNode<T>* AVLTree<T>::search(T value) const {
  return search(root, value);
}

template <typename T>
AVLTreeNode<T>* AVLTree<T>::search(AVLTreeNode<T>* node, T value) const {
  if (node == nullptr || node->data == value) {
    return node;
  } else if (value < node->data) {
    return search(node->left, value);
  } else {
    return search(node->right, value);
  }
}

template <typename T>
void AVLTree<T>::clear(AVLTreeNode<T>* node) {
  if (node != nullptr) {
    clear(node->left);
    clear(node->right);
    delete node;
  }
}
}  // namespace s21
