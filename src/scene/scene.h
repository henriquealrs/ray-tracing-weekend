#ifndef SCENE_H
#define SCENE_H

#include "objects/object.h"
#include <vector>
#include <memory>

using ObjectPtr = std::shared_ptr<Object>;

class Scene : public Object
{
    using ObjectList = std::vector<ObjectPtr>;
    ObjectList objects;
public:
    Scene();

    void add_object(const ObjectPtr obj) {
        objects.push_back(obj);
    }


    // Object interface
public:
    bool ray_hit(const Ray &ray, double t_min, double t_max, hit_record &rec) const override;
};

#endif // SCENE_H
