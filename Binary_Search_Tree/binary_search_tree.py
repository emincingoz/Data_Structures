
class BinarySearchTree:
    def __init__(self, key = None):
        self.key = key
        self.left = None
        self.right = None
        
    def add(self, key):
        # Check there is no root
        if self.key == None:
            self.key = key
        # Check where to insert
        else:
            # Check for duplicate key then stop and return
            if key == self.key: return 'No duplicates allowed in binary'
            
            # Check if value to be inserted < currentNode's value
            if key < self.key:
                # Check if there is a left node to current node if true then recurse
                if self.left:
                    self.left.add(key)
                # insert where left of current node when currentNode.left = None
                else:   self.left = BinarySearchTree(key)
            # Same steps as above here the condition we check is value to be inserted > currentNode's value
            else:
                if self.right:
                    self.right.add(key)
                else:
                    self.right = BinarySearchTree(key)
                    
    def min(self):
        current_node = self
        
        while current_node.left is not None:
            current_node = current_node.left
            
        return current_node.key
    
    def max(self):
        current_node = self
        
        while current_node.right is not None:
            current_node = current_node.right
            
        return current_node.key
                    
    def remove(self, key):
        # Check if the value we want to delete is in the tree
        if self.findNodeAndParentNode(key) == 'Not Found':  return 'Node is not in tree'
        
        # We get the node we want to delete and its parent-node from findNodeAndParentNode method
        deleting_node, parent_node = self.findNodeAndParentNode(key)
        
        # Check how many children nodes does the node we are going to delete hav by traversePreOrder from the deleting_node
        nodes_affected = deleting_node.traversePreOrder([])
        
        # if len(nodes_affected) == 1 means, the node to deleted doesn't have any children
        # So we can just check from its parent node the position(left or right) of node we want to delete
        # and point the position to 'None' i.e node is deleted
        if len(nodes_affected) == 1:
            if parent_node.left.key == deleting_node.key: 
                parent_node.left = None
            else:
                parent_node.right = None
            return 'Succesfully Deleted'
        # if len(nodes_affected) > 1 which means the node we are going to delete has 'children'
        # so the tree must be rearrenged from the deleting_node
        else: 
            # if the node we want to delete doesn't have any parent means the node to be deleted is 'root' node
            if parent_node == None:
                nodes_affected.remove(deleting_node.key)
                
                # Make the 'root' node i.e self.key,left,right to None
                # This means we need to implement a new tree again without the deleted node
                self.key = None
                self.left = None
                self.right = None
                
                # Construction of new tree
                for node_key in nodes_affected:
                    self.add(node_key)
                
                return 'Succesfully Deleted'
            
            # If the node we want to delete has a parent 
            # traverse from parent_node
            nodes_affected = parent_node.traversePreOrder([])
            
            # Deleting the node
            if parent_node.left == deleting_node:
                parent_node.left = None
            else:
                parent_node.right = None
                
            # Removing the parent_node, deleting_node and add the nodes_affected in the tree
            nodes_affected.remove(deleting_node.key)
            nodes_affected.remove(parent_node.key)
            for node_key in nodes_affected:
                self.add(node_key)
                
        return 'Succesfully Deleted'    
                    
        
    def findNodeAndParentNode(self, key, parent = None):
        # Return the node and its parent if the serched node is the first root node.
        if self.key == key: return self, parent
        if key < self.key:
            if self.left:
                return self.left.findNodeAndParentNode(key, self)
            else:
                return 'Not Found'
        else:
            if self.right:
                return self.right.findNodeAndParentNode(key, self)
            else:
                return 'Not Found'
                
    def breadthFirstSearch(self):
        current_node = self
        bfs_list = []
        queue_list = []
        queue_list.insert(0, current_node)
        
        while len(queue_list) > 0:
            current_node = queue_list.pop()
            bfs_list.append(current_node.key)
            if current_node.left:
                queue_list.insert(0, current_node.left)
            if current_node.right:
                queue_list.insert(0, current_node.right)
                
        return bfs_list
               
    # In order means first left child, then parent, at last right child
    def depthFirstSearch_INorder(self):
        return self.traverseInOrder([])

    # Pre order means first parent, then left child, at last right child
    def depthFirstSearch_PREorder(self):
        return self.traversePreOrder([])

    # Post order means first left child, then right child , at last parent
    def depthFirstSearch_POSTorder(self):
        return self.traversePostOrder([])
    
    def traverseInOrder(self, lst):
        if self.left:
            self.left.traverseInOrder(lst)
        lst.append(self.key)
        if self.right:
            self.right.traverseInOrder(lst)
        
        return lst 
            
    def traversePreOrder(self, lst):
        lst.append(self.key)
        if self.left:
            self.left.traversePreOrder(lst)
        if self.right:
            self.right.traversePreOrder(lst)
        
        return lst           
    
    def traversePostOrder(self, lst):
        if (self.left):
            self.left.traversePostOrder(lst)
        if (self.right):
            self.right.traversePostOrder(lst)
        lst.append(self.key)
        return lst         
                    
                    
def main():
    bst = BinarySearchTree()
    
    bst.add(7)
    bst.add(4)
    bst.add(9)
    bst.add(0)
    bst.add(5)
    bst.add(8)
    bst.add(13)
    
    '''
         7
       /   \
      /     \
     4       9
    / \     / \
   0   5   8   13
   
    '''
    
    
    
    #print(bst)
    #print(bst.key)
    #print(bst.left.key)
    #print(bst.right.key)
    
    print('IN order: ',bst.depthFirstSearch_INorder()) # useful in sorting the tree in ascending order
    print('PRE order:' ,bst.depthFirstSearch_PREorder()) # pre order is useful in reconstructing a tree
    print('POST order:', bst.depthFirstSearch_POSTorder()) # useful in finding the leaf nodes
    print('Breadth First Search: ', bst.breadthFirstSearch()) # useful for listing line by line
    
    print(bst.remove(5))
    print(bst.remove(9))
    print(bst.remove(7))
    
    print('PRE order:' ,bst.depthFirstSearch_PREorder()) # pre order is useful in reconstructing a tree
    
if __name__ == '__main__':
    main()
                    
            
        
                    
                
            
            