#ifndef TREEITEM_H
#define TREEITEM_H

#include <QList>

class TreeItem
{
public:
  explicit TreeItem(const QList<QString> &data, TreeItem *parentItem = 0);
  ~TreeItem();
  void appendChild(TreeItem *child);
      TreeItem *child(int row);
      int childCount() const;
      int columnCount() const;
      QVariant data(int column) const;
      int row() const;
      TreeItem *parentItem();

  private:
      QList<TreeItem*> _childItems;
      QList<QString> _itemData;
      TreeItem *_parentItem;
};


#endif // TREEITEM_H
