/* Autori : Samuel Križan   <xkriza06>
 *          Damián Sova     <xsovad06>
*/
#ifndef TRAM_H
#define TRAM_H

#include <QGraphicsEllipseItem>
#include <QVariantAnimation>
#include <QtDebug>
#include <QPen>
#include <QPainter>
#include "path.h"

//! Class represents tram for simulating tram ride
/*!
 * \brief The Tram class
 */
class Tram : public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
    public:
        //! A constructor.
        /*!
         * \brief Tram
         * Draws a mark representing a location of tram.
         * It is managed like relative position on a line.
         * \param start one ending point of line.
         * \param end another ending point of line.
         * \param loc part of line the tram is located on, in interval of <0,1>.
         * \param parent pointer to parent obj.
         */
        explicit Tram(QPointF *start,QPointF *end, float loc, QGraphicsItem *parent = nullptr);

    protected:
        //! Overriden painting function of QGraphicsEllipseItem
        /*!
         * \brief paint overided
         * \param painter
         * \param option
         * \param widget
         */
        virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) override;

    private:
        QLineF line;    /*!< Atribute representing street */
        float loc;      /*!< Atribute representing position of tram */


};

#endif // TRAM_H
