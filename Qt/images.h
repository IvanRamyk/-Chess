#ifndef IMAGES_H
#define IMAGES_H

#include <QMap>
#include <QImage>
#include <QString>
#include <iostream>

class Images
{
public:
    Images() = default;
    void load(){
        images.insert("board", QImage("../Qt/Board.png"));
        images.insert("white pawn", QImage("../Qt/pawn1.png"));
        images.insert("black pawn", QImage("../Qt/pawn.png"));
        images.insert("white knight", QImage("../Qt/horse1.png"));
        images.insert("black knight", QImage("../Qt/horse.png"));
        images.insert("white bishop", QImage("../Qt/bishop1.png"));
        images.insert("black bishop", QImage("../Qt/bishop.png"));
        images.insert("white rook", QImage("../Qt/rook1.png"));
        images.insert("black rook", QImage("../Qt/rook.png"));
        images.insert("white queen", QImage("../Qt/queen1.png"));
        images.insert("black queen", QImage("../Qt/queen.png"));
        images.insert("white king", QImage("../Qt/king1.png"));
        images.insert("black king", QImage("../Qt/king.png"));
        images.insert("selected cell", QImage("../Qt/selected.jpg"));
    }
    QImage& get(const QString& imgName){
        return images[imgName];
    }
private:
    QMap <QString, QImage> images;
};

#endif // IMAGES_H
