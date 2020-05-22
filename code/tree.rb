
class Node
  attr_accessor :data, :left, :right, :order

  def initialize(val)
    @data = val
    @left = @right = nil
    @order = 0
  end
end

# @author Anant Agrawal 
class BstTree
  attr_accessor :root

  def initialize
    @root = nil
  end

  # @param val [Integer]
  def insert(val)
    self.root = insert_util(root, val)
  end

  def inorder
    inorder_util(root)
  end

  def print_leaf
    arr = []
    mark_tree(root, arr)
    arr.sort! { |x, y| x[0] <=> y[0]}
    puts arr
  end

  def mark_tree(root, arr)
    return 0 if root.nil?
    root.order = [mark_tree(root.left, arr), mark_tree(root.right, arr)].max + 1
    arr.push([root.order, root.data])
    root.order
  end

  private

  def insert_util(root, val)
    return Node.new(val) if root.nil?

    if val < root.data
      root.left = insert_util(root.left, val)
    else
      root.right = insert_util(root.right, val)
    end
    root
  end

  def inorder_util(root)
    return if root.nil?

    inorder_util(root.left)
    puts root.data
    inorder_util(root.right)
  end
end

t = BstTree.new
t.insert(8)
t.insert(3)
t.insert(10)
t.insert(9)
t.insert(4)
t.print_leaf