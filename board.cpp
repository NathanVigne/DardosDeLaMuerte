#include "board.h"



Board::Board(QGraphicsScene *parent, QLabel *label)
    : QGraphicsScene(parent)
{

    // Zone ou l'on construit la board
    Secteur *a = new Secteur(nullptr,label);
    a->loadBull();
    a->loadOut();
    a->loadSection(numberType::VINGT);
    a->setPos(0,0);
    addItem(a);

    Secteur *b = new Secteur(nullptr,label);
    b->loadSection(numberType::UN);
    b->setPos(0,0);
    b->setRotation(18);
    addItem(b);

    Secteur *c = new Secteur(nullptr,label);
    c->loadSection(numberType::DIXHUIT);
    c->setPos(0,0);
    c->setRotation(36);
    addItem(c);

    Secteur *d = new Secteur(nullptr,label);
    d->loadSection(numberType::QUATRE);
    d->setPos(0,0);
    d->setRotation(54);
    addItem(d);

    Secteur *e = new Secteur(nullptr,label);
    e->loadSection(numberType::TREIZE);
    e->setPos(0,0);
    e->setRotation(72);
    addItem(e);

    Secteur *f = new Secteur(nullptr,label);
    f->loadSection(numberType::SIX);
    f->setPos(0,0);
    f->setRotation(90);
    addItem(f);

    Secteur *g = new Secteur(nullptr,label);
    g->loadSection(numberType::DIX);
    g->setPos(0,0);
    g->setRotation(108);
    addItem(g);

    Secteur *h = new Secteur(nullptr,label);
    h->loadSection(numberType::QUINZE);
    h->setPos(0,0);
    h->setRotation(126);
    addItem(h);

    Secteur *i = new Secteur(nullptr,label);
    i->loadSection(numberType::DEUX);
    i->setPos(0,0);
    i->setRotation(144);
    addItem(i);

    Secteur *j = new Secteur(nullptr,label);
    j->loadSection(numberType::DIXSEPT);
    j->setPos(0,0);
    j->setRotation(162);
    addItem(j);

    Secteur *k = new Secteur(nullptr,label);
    k->loadSection(numberType::TROIS);
    k->setPos(0,0);
    k->setRotation(180);
    addItem(k);

    Secteur *l = new Secteur(nullptr,label);
    l->loadSection(numberType::DIXNEUF);
    l->setPos(0,0);
    l->setRotation(-162);
    addItem(l);

    Secteur *m = new Secteur(nullptr,label);
    m->loadSection(numberType::SEPT);
    m->setPos(0,0);
    m->setRotation(-144);
    addItem(m);

    Secteur *n = new Secteur(nullptr,label);
    n->loadSection(numberType::SEIZE);
    n->setPos(0,0);
    n->setRotation(-126);
    addItem(n);

    Secteur *o = new Secteur(nullptr,label);
    o->loadSection(numberType::HUIT);
    o->setPos(0,0);
    o->setRotation(-108);
    addItem(o);

    Secteur *p = new Secteur(nullptr,label);
    p->loadSection(numberType::ONZE);
    p->setPos(0,0);
    p->setRotation(-90);
    addItem(p);

    Secteur *q = new Secteur(nullptr,label);
    q->loadSection(numberType::QUATORZE);
    q->setPos(0,0);
    q->setRotation(-72);
    addItem(q);

    Secteur *r = new Secteur(nullptr,label);
    r->loadSection(numberType::NEUF);
    r->setPos(0,0);
    r->setRotation(-54);
    addItem(r);

    Secteur *s = new Secteur(nullptr,label);
    s->loadSection(numberType::DOUZE);
    s->setPos(0,0);
    s->setRotation(-36);
    addItem(s);

    Secteur *t = new Secteur(nullptr,label);
    t->loadSection(numberType::CINQ);
    t->setPos(0,0);
    t->setRotation(-18);
    addItem(t);

}


