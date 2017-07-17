structure Thread :> THREAD =
struct

exception IncompatiblePriorities

structure F = MLtonParallelFutureSuspend
structure P = Priority
structure B = MLtonParallelBasic

type 'a t = 'a F.t * P.t

fun spawn (f: unit -> 'a) (prio: P.t) : 'a t =
    (F.futurePrio (prio, f), prio)

fun sync ((t, prio): 'a t) =
    let val cp = B.currentPrio ()
    in
        if P.ple(cp, prio) then
            F.touch t
        else
            raise IncompatiblePriorities
    end

end
