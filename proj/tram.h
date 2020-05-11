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
        //! TODO
        /*!
         * \brief Tram
         * \param start
         * \param end
         * \param loc
         * \param parent
         */
        explicit Tram(QPointF *start,QPointF *end, float loc, QGraphicsItem *parent = nullptr);

    protected:
        //! TODO
        /*!
         * \brief paint overided
         * \param painter
         * \param option
         * \param widget
         */
        virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) override;

    private:
        QLineF line;    /*< Atribute representing street */
        float loc;      /*< Atribute representing position of tram */

};

#endif // TRAM_H
